/* En los archivos (*.c) se pueden poner tanto DECLARACIONES como DEFINICIONES de C, así como directivas de preprocesador */
/* Recordar solamente indicar archivos *.h en las directivas de preprocesador #include, nunca archivos *.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "general.h"

extern YYLTYPE yylloc;
extern char *yytext; 
int size_vec_arguments = 0;

extern int yyleng;
char* invalid_string;
t_error* new_error = NULL;

void inicializarUbicacion(void)
{
    yylloc.first_line = yylloc.last_line = INICIO_CONTEO_LINEA;
    yylloc.first_column = yylloc.last_column = INICIO_CONTEO_COLUMNA;
}

void reinicializarUbicacion(void)
{
    yylloc.first_line = yylloc.last_line;
    yylloc.first_column = yylloc.last_column;
}

char* token_buffer = NULL;  // Buffer dinámico para almacenar los tokens
int token_buffer_pos = 0;   // Posición actual en el buffer
int token_buffer_size = 0;  // Tamaño actual del buffer

void reset_token_buffer() {
    if (token_buffer) {
        token_buffer[0] = '\0';  // Resetea el buffer
    }
    token_buffer_pos = 0;
}

// Función para agregar un token al buffer dinámico
void append_token(const char* token) {
    int len = strlen(token);
    if (!token_buffer || token_buffer_pos + len + 2 > token_buffer_size) {  // Si el buffer es nulo o no hay suficiente espacio, se debe reasignar memoria
        token_buffer_size = token_buffer_size + len + 2;  // +2 para el espacio y el terminador nulo
        char* new_buffer = (char*)realloc(token_buffer, token_buffer_size);
        if (!new_buffer) {
            printf("Error al asignar memoria para token_buffer");
            exit(EXIT_FAILURE);
        }
        token_buffer = new_buffer;
        token_buffer[0] = '\0';
    }

    // Agregar un espacio si el buffer ya tiene contenido
    if (token_buffer[0] != '\0') {
        strcat(token_buffer, " ");
        token_buffer_pos++;
    }

    // Agregar el nuevo token
    strcat(token_buffer, token);
    token_buffer_pos += len;
}

void yerror(YYLTYPE ubicacion) {
    // Asignar memoria para el nuevo error
    t_error *new_error = (t_error *)malloc(sizeof(t_error));
    if (!new_error) {
        printf("Error al asignar memoria para el nuevo error");
        exit(EXIT_FAILURE);
    }

    new_error->line = ubicacion.first_line;

    new_error->message = (char*)malloc(token_buffer_pos + 1);  // +1 para el terminador nulo
    if (!new_error->message) {
        printf("Error al asignar memoria para el mensaje de error");
        exit(EXIT_FAILURE);
    }

    strncpy(new_error->message, token_buffer, token_buffer_pos + 1);

    insert_node(&error_list, new_error, sizeof(t_error));
}

void free_token_buffer() {
    if (token_buffer) {
        free(token_buffer);
        token_buffer = NULL;
    }
}

void save_function(char* type, const char* return_type, const char* id) {
    data_function->return_type = strdup(return_type);
    data_function->name = strdup(id);
    data_function->type = type;
}

void init_structures() { // Iniciar todas las estructuras
    data_variable = (t_variable*)malloc(sizeof(t_variable));
    if (!data_variable) {
        printf("Error al asignar memoria para data_variable\n");
        exit(EXIT_FAILURE);
    }
    data_variable->line = 0;
    data_variable->type = NULL;      
    data_variable->variable = NULL;

    data_function = (t_function*)malloc(sizeof(t_function));
    if (!data_function) {
        printf("Error al asignar memoria para data_function\n");
        exit(EXIT_FAILURE);
    }
    data_function->name = NULL;
    data_function->line = 0;
    data_function->type = NULL;
    data_function->parameters = NULL;
    data_function->return_type = NULL;

    t_parameter* data_parameter = (t_parameter*)malloc(sizeof(t_parameter));
    if(!data_parameter) {
        printf("Error al asignar memoria para data_parameter\n");
        exit(EXIT_FAILURE);
    }
    data_parameter->name = NULL;
    data_parameter->type = NULL;

    data_intoken = (t_sent_or_unrecognised_token*)malloc(sizeof(t_sent_or_unrecognised_token));
    if(!data_intoken) {
        printf("Error al asignar memoria para data_intoken");
        exit(EXIT_FAILURE);
    }
    data_intoken->column = 0;
    data_intoken->line = 0;
    data_intoken->type = NULL;

    data_sem_error = (t_semantic_error*)malloc(sizeof(t_semantic_error));
    if(!data_sem_error) {
        printf("Error al asignar memoria para data_sem_error");
        exit(EXIT_FAILURE);
    }
    data_sem_error->msg = NULL;

    data_sent = (t_sent_or_unrecognised_token*)malloc(sizeof(t_sent_or_unrecognised_token));
    if (!data_sent) {
        printf("Error al asignar memoria para data_sent");
        exit(EXIT_FAILURE);
    }
    data_sent->column = 0;
    data_sent->line = 0;

    data_symbol = (t_symbol_table*)malloc(sizeof(t_symbol_table));
    if(!data_symbol) {
        printf("Error al asignar memoria para data_symbol");
        exit(EXIT_FAILURE);
    }
    data_symbol->column = 0;
    data_symbol->line = 0;
    data_symbol->scope = 0;
    data_symbol->symbol = 0;
    data_symbol->identifier = NULL;
    data_symbol->data = NULL;

    new_error = (t_error*)malloc(sizeof(t_error));
    if (!new_error) {
        printf("Error al asignar memoria para el nuevo error!\n");
        exit(EXIT_FAILURE);
    }
    new_error->line = 0;
    new_error->message = NULL; // Inicializa el puntero message a NULL
    
    invalid_string = (char*)malloc(1);
    if (!invalid_string) {
        printf("Error al asignar memoria para invalid_string\n");
        return;
    }
    invalid_string[0] = '\0';
}

void add_unrecognised_token(const char* intoken) {
    data_intoken -> type = strdup(intoken);
    data_intoken -> line = yylloc.first_line;
    data_intoken -> column = yylloc.first_column;
    insert_node(&intokens, data_intoken, sizeof(t_sent_or_unrecognised_token));
}

void add_sent(const char* tipo_sentencia, int line, int column) {
    data_sent->type = strdup(tipo_sentencia);
    if (!data_sent->type) {
        printf("Error al asignar memoria para el tipo de sentencia en %i:%i", line, column);
        exit(EXIT_FAILURE);
    }
    data_sent->line = line;
    data_sent->column = column;
    insert_sorted_node(&sentencias, data_sent, sizeof(t_sent_or_unrecognised_token), compare_lines);
}

void insert_sorted_node(GenericNode** list, void* new_data, size_t data_size, int (*compare)(const void*, const void*)) {
    GenericNode* new_node = (GenericNode*)malloc(sizeof(GenericNode));
    if (!new_node) {
        printf("Error al asignar memoria para el nuevo nodo");
        exit(EXIT_FAILURE);
    }
    new_node->data = malloc(data_size);
    if (!new_node->data) {
        printf("Error al asignar memoria para los datos del nuevo nodo");
        exit(EXIT_FAILURE);
    }
    memcpy(new_node->data, new_data, data_size);
    new_node->next = NULL;

    if (!(*list) || compare(new_data, (*list)->data) <= 0) {
        new_node->next = *list;
        *list = new_node;
        return;
    }

    GenericNode* current = *list;
    while (current->next != NULL && compare(new_data, current->next->data) > 0) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
} 


void insert_node(GenericNode** list, void* new_data, size_t data_size) {
    GenericNode* new_node = (GenericNode*)malloc(sizeof(GenericNode));
    if (!new_node) {
        printf("Error al asignar memoria para el nuevo nodo");
        exit(EXIT_FAILURE);
    }

    new_node->data = malloc(data_size);
    if (!new_node->data) {
        printf("Error al asignar memoria para los datos del nuevo nodo");
        free(new_node);
        exit(EXIT_FAILURE);
    }
    memcpy(new_node->data, new_data, data_size);
    new_node->next = NULL;

    if (!(*list)) {
        *list = new_node;
        return;
    }

    GenericNode* current = *list;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
}

void print_list(GenericNode* list, void (*print_node)(void*)) {
    if(list) {
        GenericNode* aux = list;
        while(aux) {
            print_node(aux->data);
            aux = aux->next;
        }
    } else {
        printf("-\n");
    }
    printf("\n\n");
}

void print_variable(void* data) {
    t_variable* var = (t_variable*)data;
    printf("%s: %s, linea %i, columna %i\n", var->variable, var->type, var->line, var->column);
}

void print_function(void* data) {
    t_function* func = (t_function*)data;
    printf("%s: %s, input: ", func->name, func->type);
    
    if (func->parameters) {
        GenericNode* aux = func->parameters;
        while (aux) {
            t_parameter* param = (t_parameter*)aux->data;
            if (param->type && param->name) {
                printf("%s %s", param->type, param->name);
            } else if (param->type) {
                printf("%s", param->type);
            } else {
                printf("Tipo de parametro nulo");
            }
            aux = aux->next;
            if (aux) {
                printf(", ");
            }
        }
    } else {
        printf("void");
    }
    printf(", retorna: %s, linea %i\n", func->return_type, func->line);
}

void print_syntax_error(void* data) {
    t_error* err = (t_error*)data;
    printf("\"%s\": linea %d\n", err->message, err->line);
}

void print_lexical_error(void* data) {
    t_sent_or_unrecognised_token* token = (t_sent_or_unrecognised_token*)data;
    printf("%s: linea %i, columna %i\n", token->type, token->line, token->column);
}

void print_semantic_error(void* data) {
    t_semantic_error* err = (t_semantic_error*)data;
    printf("%s\n", err->msg);
}

void print_lists() {
    printf("* Listado de variables declaradas (tipo de dato y numero de linea):\n");
    print_list(variable, print_variable);

    printf("* Listado de funciones declaradas y definidas:\n");
    print_list(function, print_function);

    printf("* Listado de errores semanticos:\n");
    print_list(semantic_errors, print_semantic_error);

    printf("* Listado de errores sintacticos:\n");
    print_list(error_list, print_syntax_error);

    printf("* Listado de errores lexicos:\n");
    print_list(intokens, print_lexical_error);
}

void free_list(GenericNode** list, void (*free_data)(void*)) { 
    GenericNode* temp;
    while (*list) {
        temp = *list;
        *list = (*list)->next;
        if(free_data) {
            free_data(temp->data);  
        }
        if(temp)
            free(temp);
    }
    *list = NULL; 
}

void free_function(void* data) {
    t_function* func = (t_function*) data;
    
    if (func && func->parameters) {
        free_list(&(func->parameters), free);
    }

    free(func->name);
    free(func->return_type);
    free(func); 
}

void free_all_lists() {
    free_list(&variable, free); 
    free_list(&function, free_function);  // Como function tiene sublsita por nodo, usamos free_function
    free_list(&error_list, free);
    free_list(&intokens, free);
    free_list(&sentencias, free);
    free_list(&semantic_errors, free);
    free_list(&symbol_table, free);
}

int compare_lines(const void* a, const void* b) {
    const t_sent_or_unrecognised_token* sent_a = (const t_sent_or_unrecognised_token*)a;
    const t_sent_or_unrecognised_token* sent_b = (const t_sent_or_unrecognised_token*)b;

    return sent_a->line - sent_b->line;
}
                                    
int fetch_element(SYMBOL_TYPE symbol, void* wanted, compare_element cmp) {
    GenericNode* current = symbol_table;
    while (current) {
        t_symbol_table* sym = (t_symbol_table*)current->data;
        if(sym->symbol == symbol) {
            if (cmp(sym->data, wanted) == 1) { 
                return 1;
            }
        }
        current = current->next;
    }
    return 0;
}

int fetch_parameter(const char* wanted) {
    GenericNode* current = data_function->parameters; 
    while (current) {
        t_parameter* param = (t_parameter*)current->data;
        if(param && param->name) {
            if (strcmp(param->name, wanted) == 0) { 
                return 1; 
            }
        }
        current = current->next;  
    }
    return 0; 
}

int fetch_type_parameter(t_function* function, char* wanted) {
    GenericNode* current = function->parameters; 
    while (current) {
        t_parameter* param = (t_parameter*)current->data;
        if(param && param->type) {
            if (strcmp(param->type, wanted) == 0) { 
                return 1; 
            }
        }
        current = current->next;  
    }
    return 0; 
}

int get_quantity_parameters(GenericNode* list) {
    GenericNode* aux = list;
    int quantity = 0;
    while(aux) {
        t_parameter* temp = (t_parameter*)aux -> data;
        if(temp && strcmp(temp->type, "void") == 0) {
            quantity --;
        }
        quantity ++;
        aux = aux -> next;
    }
    return quantity;
}

// Busca una variable que ÚNICAMENTE tenga el mismo IDENTIFICADOR que la trackeada
int compare_ID_variable(void* data, void* wanted) {
    t_variable* var_data = (t_variable*)data;
    t_variable* data_wanted = (t_variable*)wanted;
    return strcmp(var_data->variable, data_wanted->variable) == 0;
}

// Busca un IDENTIFICADOR NO declarado en los parametros de las invocaciones (ToDo: fijarse si se puede acoplar con el compare de arriba)
int compare_ID_parameter(void* data, void* wanted) {
    t_variable* var_data = (t_variable*)data;
    char* data_wanted = (char*)wanted;
    return strcmp(var_data->variable, data_wanted) == 0;
}

// Busca una funcion con el mismo IDENTIFICADOR que la trackeada pero con distinto tipo
int compare_ID_and_different_type_functions(void* data, void* wanted) {
    t_function* function_var = (t_function*)data;
    t_function* data_wanted = (t_function*)wanted;
    if(strcmp(function_var->return_type, data_wanted->return_type) != 0)
        return strcmp(function_var->name, data_wanted->name) == 0;
    
    return 0;
}

int compare_ID_functions(void* data, void* wanted) {
    t_function* function_var = (t_function*)data;
    char* data_wanted = (char*)wanted;

    return strcmp(function_var->name, data_wanted) == 0 && 
           strcmp(function_var->type, "definicion") == 0;
}


// Busca una variable en la lista de variables declaradas que tenga mismo IDENTIFICADOR y distinto tipo
int compare_ID_and_diff_type_variable(void* data, void* wanted) {
    t_variable* var_data = (t_variable*)data;
    t_variable* data_wanted = (t_variable*)wanted;

    return strcmp(var_data->variable, data_wanted->variable) == 0 &&
           strcmp(var_data->type, data_wanted->type) != 0;
}

// Busca una variable en la lista de variables declaradas que tenga mismo tipo y IDENTIFICADOR que la trackeada
int compare_ID_and_type_variable(void* data, void* wanted) {
    t_variable* var_data = (t_variable*)data;
    t_variable* data_wanted = (t_variable*)wanted;

    return strcmp(var_data->variable, data_wanted->variable) == 0 &&
           strcmp(var_data->type, data_wanted->type) == 0;
}

// Busca el IDENTIFICADOR de la variable pasada por parametro en la lista de funciones
int compare_ID_between_variable_and_function(void* data, void* wanted) {
    t_function* function_var = (t_function*)data;
    t_variable* data_wanted = (t_variable*)wanted;
    return strcmp(function_var->name, data_wanted->variable) == 0;
}

// Busca un IDENTIFICADOR x en la lista de funciones
int compare_char_and_ID_function(void* data, void* wanted) {
    t_function* function_var = (t_function*)data;
    char* data_wanted = (char*)wanted;
    return strcmp(function_var->name, data_wanted) == 0;
}

// Busca un IDENTIFICADOR x en la lista de variables
int compare_char_and_ID_variable(void* data, void* wanted) {
    t_variable* data_var = (t_variable*)data;
    char* data_wanted = (char*)wanted;
    return strcmp(data_var->variable, data_wanted) == 0;
}

// Busca el IDENTIFICADOR de la variable pasada por parametro en la lista de funciones DEFINIDAS O DECLARADAS (difiere por definicion y declaracion)
int compare_ID_in_declaration_or_definition(void* data, void* wanted) { 
    t_function* function_var = (t_function*)data;
    t_function* data_wanted = (t_function*)wanted;
    if(strcmp(function_var->name, data_wanted->name) == 0) {
        if(strcmp(function_var->type, data_wanted->type) == 0)
            return 1;
        else {
            if(strcmp(function_var->type, "definicion") == 0 && strcmp(data_wanted->type, "declaracion") == 0) {
                return 1;
            }
        }
    }
    return 0;
}

// Busca el IDENTIFICADOR de la variable en los parametros de la funcion
int compare_variable_and_parameter(void* data, void* wanted) {
    t_parameter* data_param = (t_parameter*)data;
    t_variable* data_wanted = (t_variable*)wanted;
    return strcmp(data_param->name, data_wanted->variable) == 0;
}

int compare_void_function(void* data, void* wanted) {
    t_function* data_func = (t_function*)data;
    char* data_wanted = (char*)wanted;
    return strcmp(data_func->name, data_wanted) == 0 && strcmp(data_func->return_type, "void") == 0;
}

void insert_if_not_exists() {
    if (!fetch_element(VARIABLE, data_variable, compare_ID_variable) &&
        !fetch_element(FUNCTION, data_variable, compare_ID_between_variable_and_function)) {
        insert_node(&variable, data_variable, sizeof(t_variable));
        insert_symbol(VARIABLE);
    }
}

char* concat_parameters(GenericNode* parameters) {
    char* string_parameters = malloc(1);
    string_parameters[0] = '\0';

    GenericNode* aux = parameters;
    while (aux) {
        t_parameter* param = (t_parameter*) aux->data;

        size_t new_size = strlen(string_parameters) + strlen(param->type) + 3; // El +3 es para el caracter vacio, la coma y el espacio
        string_parameters = realloc(string_parameters, new_size);

        strcat(string_parameters, param->type);
        aux = aux -> next;
        if(aux) {
            strcat(string_parameters, ", ");
        }
    }

    return string_parameters;
}

void insert_symbol(SYMBOL_TYPE symbol_type) {
    data_symbol->symbol = symbol_type;
    switch (data_symbol->symbol) {
        case FUNCTION:
            data_symbol->identifier = strdup(data_function->name);
            data_symbol->data = malloc(sizeof(t_function));
            if (!data_symbol->data) {
                printf("Error allocating memory for data_symbol->data\n");
                exit(EXIT_FAILURE);
            }
            memcpy(data_symbol->data, data_function, sizeof(t_function));
            break;

        case VARIABLE:
            data_symbol->identifier = strdup(data_variable->variable);
            data_symbol->data = malloc(sizeof(t_variable));
            if (!data_symbol->data) {
                printf("Error allocating memory for data_symbol->data\n");
                exit(EXIT_FAILURE);
            }
            memcpy(data_symbol->data, data_variable, sizeof(t_variable));
            break;

        default:
            printf("Unknown symbol type\n");
            break;
    }

    insert_node(&symbol_table, data_symbol, sizeof(t_symbol_table));
}

t_symbol_table* get_element(SYMBOL_TYPE symbol_type, void* wanted, compare_element cmp) {
    GenericNode* current = symbol_table;
    while (current) {
        t_symbol_table* aux = (t_symbol_table*)current->data;
        if(aux->symbol == symbol_type) {
            if (cmp(aux->data, wanted) == 1) {
                return aux;
            }
        }
        current = current->next;
    }
    return NULL;
}

void insert_sem_error_different_symbol(int column) {
    t_symbol_table* existing_symbol = get_element(FUNCTION, data_function, compare_ID_and_different_type_functions);
    if(existing_symbol) {
        t_function* existing_function = (t_function*)existing_symbol->data;
        if(existing_function) {
            char* new_parameters = concat_parameters(data_function -> parameters);
            char* old_parameters = concat_parameters(existing_function -> parameters);
            _asprintf(&data_sem_error->msg, "%i:%i: conflicto de tipos para '%s'; la ultima es de tipo '%s(%s)'\nNota: la declaracion previa de '%s' es de tipo '%s(%s)': %i:%i",
                    data_function->line, column, data_function->name,
                    data_function->return_type, new_parameters, existing_function->name, 
                    existing_function->return_type, old_parameters,
                    existing_symbol->line, existing_symbol->column);
            insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
        }
    }
}

void insert_sem_error_invocate_function(int line, int column, char* identifier, int quant_parameters) {
    if(!fetch_element(FUNCTION, data_function, compare_ID_and_different_type_functions)) {
        _asprintf(&data_sem_error -> msg, "%i:%i: Funcion '%s' sin declarar", line, column, identifier);
        insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
    } else if(!fetch_element(FUNCTION, identifier, compare_char_and_ID_function)) {
        insert_sem_error_invalid_identifier(line, column, identifier);
    } else if(fetch_element(FUNCTION, identifier, compare_char_and_ID_function)) {
        insert_sem_error_too_many_or_few_parameters(line, column, identifier, quant_parameters);
    }
}

void insert_sem_error_invalid_identifier(int line, int column, char* identifier) {
    t_symbol_table* existing_symbol = get_element(VARIABLE, identifier, compare_char_and_ID_variable);
    if(existing_symbol) {
        _asprintf(&data_sem_error -> msg, "%i:%i: El objeto invocado '%s' no es una funcion o un puntero a una funcion\nNota: declarado aqui: %i:%i",
                line, column, identifier, 
                existing_symbol -> line, existing_symbol -> column);
        insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
    }
}

void insert_sem_error_too_many_or_few_parameters(int line, int column, char* identifier, int quant_parameters) {
    t_symbol_table* existing_symbol = get_element(FUNCTION, identifier, compare_char_and_ID_function);
    if(existing_symbol) {
        t_function* existing_function = (t_function*)existing_symbol->data;
        if(get_quantity_parameters(existing_function -> parameters) > quant_parameters) {
            _asprintf(&data_sem_error -> msg, "%i:%i: Insuficientes argumentos para la funcion '%s'\nNota: declarado aqui: %i:%i",
                    line, column, identifier,
                    existing_symbol->line, existing_symbol->column);
            insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
        } else if(get_quantity_parameters(existing_function -> parameters) < quant_parameters) {
            _asprintf(&data_sem_error -> msg, "%i:%i: Demasiados argumentos para la funcion '%s'\nNota: declarado aqui: %i:%i",
                    line, column, identifier,
                    existing_symbol->line, existing_symbol->column);
            insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
        }
    }
}

void handle_redeclaration(int redeclaration_line, int redeclaration_column, const char* identifier) {
    t_symbol_table* existing_symbol = get_element(FUNCTION, data_variable, compare_ID_between_variable_and_function); // Si no encuentra, asigna null, por ende no hace falta reinicializar en las demas

    if (existing_symbol) {
        check_function_redeclaration(existing_symbol, redeclaration_line, redeclaration_column, identifier);
        return;
    }

    existing_symbol = get_element(VARIABLE, data_variable, compare_ID_and_type_variable);

    if (existing_symbol) {
        check_variable_redeclaration(existing_symbol, redeclaration_line, redeclaration_column, identifier);
        return;
    }
    
    existing_symbol = get_element(VARIABLE, data_variable, compare_ID_and_diff_type_variable);
    if (existing_symbol) {
        check_type_conflict(existing_symbol, redeclaration_line, redeclaration_column, identifier);
    }
}

void handle_function_redefinition(int line, int column, char* identifier) {
    t_symbol_table* existing_symbol = (t_symbol_table*)get_element(FUNCTION, identifier, compare_ID_functions);
    if(existing_symbol){ 
        t_function* existing_function = (t_function*)existing_symbol->data;
        if(existing_function){
            char* old_parameters = concat_parameters(existing_function -> parameters);
            _asprintf(&data_sem_error->msg, "%i:%i: Redefinicion de '%s' \nNota: la definicion previa de '%s' es de tipo '%s(%s)': %i:%i", 
                line, column, identifier, existing_function->name, existing_function->return_type,
                old_parameters, existing_symbol->line, existing_symbol->column);
            insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
            data_function->parameters = NULL;
        }
    }
}

void check_function_redeclaration(t_symbol_table* symbol, int line, int column, const char* id) {
    t_function* existing_function = (t_function*)symbol->data;
    _asprintf(&data_sem_error->msg, "%i:%i: '%s' redeclarado como un tipo diferente de simbolo\nNota: la declaracion previa de '%s' es de tipo '%s(%s)': %i:%i", 
            line, column, id, 
            existing_function->name, existing_function->return_type, existing_function->return_type, 
            symbol->line, symbol->column);
    insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
}

void check_variable_redeclaration(t_symbol_table* symbol, int line, int column, const char* id) {
    t_variable* existing_variable = (t_variable*)symbol->data;
    _asprintf(&data_sem_error->msg, "%i:%i: Redeclaracion de '%s'\nNota: la declaracion previa de '%s' es de tipo '%s': %i:%i", 
            line, column, id,
            existing_variable->variable, existing_variable->type,
            existing_variable->line, existing_variable->column);
    insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
}

void check_type_conflict(t_symbol_table* symbol, int line, int column, const char* id) {
    t_variable* existing_variable = (t_variable*)symbol->data;
    _asprintf(&data_sem_error->msg, "%i:%i: conflicto de tipos para '%s'; la ultima es de tipo '%s'\nNota: la declaracion previa de '%s' es de tipo '%s': %i:%i",
            line, column, id,
            data_variable->type, existing_variable->variable, 
            existing_variable->type, existing_variable->line, 
            existing_variable->column);
    insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
}

int _asprintf(char **strp, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
    int size;
#ifdef _WIN32
    size = _vscprintf(fmt, args) + 1;  // +1 para el terminador nulo en Windows
#else
    size = vsnprintf(NULL, 0, fmt, args) + 1;  // +1 para el terminador nulo en Linux
#endif

    // Terminamos el uso de args para reiniciarlo después
    va_end(args);

    if (size <= 0) {
        return -1;  // Error al calcular el tamaño
    }

    *strp = (char *)malloc(size);
    if (*strp == NULL) {
        return -1;  // Error al asignar memoria
    }

    // Volvemos a inicializar el va_list
    va_start(args, fmt);
    
    // Genera la cadena formateada
#ifdef _WIN32
    vsnprintf_s(*strp, size, size, fmt, args);  // Windows
#else
    vsnprintf(*strp, size, fmt, args);  // Linux/Unix
#endif

    va_end(args);
    return size - 1;  // Devuelve la longitud de la cadena sin contar el terminador nulo
}

void return_conflict_types(t_symbol_table* existing_symbol, int line, int column){ // ToDo: Delegar
        t_function* existing_function = (t_function*)existing_symbol->data;

        if(strcmp(existing_function->return_type, "void") != 0) {
            if(string_flag) {
                _asprintf(&data_sem_error->msg, "%i:%i: Incompatibilidad de tipos al retornar el tipo '%s' pero se esperaba '%s'", 
                        line, column + 1, "char *", existing_function->return_type);
                insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
                string_flag = 0;
            } else {
                t_symbol_table* symbol = (t_symbol_table*)get_element(FUNCTION, type_aux, compare_void_function);
                if(symbol) {
                    t_function* function = (t_function*)symbol->data;
                    char* parameters = concat_parameters(function->parameters);
                    _asprintf(&data_sem_error->msg, "%i:%i: Incompatibilidad de tipos al retornar el tipo '%s (*)(%s)' pero se esperaba '%s'", 
                            line, column + 1, function->return_type, parameters, existing_function->return_type);
                    insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
                    }
                }
        } else {
            if(semicolon_flag) {
                _asprintf(&data_sem_error->msg, "%i:%i: 'return' sin valor en una funcion que no retorna void\nNota: declarado aqui: %i:%i", 
                line, column, existing_symbol->line, existing_symbol->column);
                insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
                string_flag = 0;
            }
        }
}

void add_argument(int line, int column, TYPES type) {
    t_arguments* temp = realloc(invocated_arguments, (size_vec_arguments + 1) * sizeof(t_arguments));
    if (temp == NULL) {
        printf("Error al redimensionar la memoria.\n");
        return;
    }
    
    invocated_arguments = temp;

    invocated_arguments[size_vec_arguments].line = line;
    invocated_arguments[size_vec_arguments].column = column;
    invocated_arguments[size_vec_arguments].type = type;

    size_vec_arguments++;
}

void free_invocated_arguments() {
    if (invocated_arguments == NULL) {
        return;  // Si ya es NULL, no hay nada que liberar
    }

    for (int i = 0; i < size_vec_arguments; i++) {
        free(invocated_arguments[i].name);  // Liberar el campo name
    }

    free(invocated_arguments);

    invocated_arguments = NULL;
    size_vec_arguments = 0;
}

void* get_parameter(GenericNode* list, int index) {
    GenericNode* current = list;
    int count = 0;
    while (current && count < index) {
        current = current->next;
        count++;
    }

    if (current != NULL) {
        return current->data;
    } else {
        return NULL;
    }
}

void manage_conflict_types(int line, int column) {
    if(!fetch_element(FUNCTION, data_function, compare_ID_in_declaration_or_definition) && !fetch_element(FUNCTION, data_function, compare_ID_and_different_type_functions)) {
        insert_node(&function, data_function, sizeof(t_function));
        data_symbol -> line = line;
        data_symbol -> column = column;
        insert_symbol(FUNCTION);
        data_function->parameters = NULL;
        position = 0;
    } else {
        insert_sem_error_different_symbol(column);
        data_function->parameters = NULL; 
    }
}

void manage_conflict_arguments (char* identifier) { // ToDo: delegar cada "case"
    t_symbol_table* existing_symbol = (t_symbol_table*)get_element(FUNCTION, identifier, compare_char_and_ID_function);
    if(existing_symbol) {
        t_function* func = (t_function*)existing_symbol->data;
        int quant = get_quantity_parameters(func->parameters);
        for(int i = 0; i < quant; i++) {
            switch(invocated_arguments[i].type) {
                case STRING:
                    t_parameter* param = (t_parameter*)get_parameter(func->parameters, i);
                    _asprintf(&data_sem_error->msg, "%i:%i: Incompatibilidad de tipos para el argumento %i de '%s'\nNota: se esperaba '%s' pero el argumento es de tipo '%s': %i:%i",
                            invocated_arguments[i].line, invocated_arguments[i].column, i + 1,
                            func->name, param->type, "char *", param->name_line, param->name_column);
                    insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
                    break;
                case ID:
                    if(!fetch_element(FUNCTION, type_aux, compare_void_function)) {
                        t_symbol_table* sym = (t_symbol_table*)get_element(FUNCTION, type_aux, compare_char_and_ID_function);
                        if(sym) {
                            t_function* function = (t_function*)sym->data;
                            t_parameter* param = (t_parameter*)get_parameter(func->parameters, i);
                            char* parameters_concat = concat_parameters(function->parameters);
                            _asprintf(&data_sem_error->msg, "%i:%i: Incompatibilidad de tipos para el argumento %i de '%s'\nNota: se esperaba '%s' pero el argumento es de tipo '%s (*)(%s)': %i:%i",
                                    invocated_arguments[i].line, invocated_arguments[i].column, i + 1,
                                    func->name, param->type, function->return_type, parameters_concat, 
                                    param->line, param->column);
                            insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
                        }
                    }
                default:
                    break;
            }
        }
    } 
}

// Devuelve, si existe, un paramtro de la funcion actual dado un nombre
t_parameter* get_param(const char* wanted) {
    GenericNode* current = data_function->parameters; 

    while (current) {
        t_parameter* param = (t_parameter*)current->data;
        if (param && strcmp(param->name, wanted) == 0) {
            return param;
        }
        current = current->next;
    }

    // Si no se encuentra el parametro devuelve NULL
    return NULL;
}

char* type_to_string(TYPES type) {
    switch (type) {
        case INT: return "int";
        case NUMBER: return "double";
        case STRING: return "char *";
        default: return "unknown"; 
    }
}

void check_assignation_types (t_variable_value declarator, t_variable_value initializer, int line, int column) {

    if (declarator.type != ID) { // No es un valor L modificable
        _asprintf(&data_sem_error->msg, "%i:%i: Se requiere un valor-L modificable como operando izquierdo de la asignacion", line, column - 2);
        insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
        return;
    }

    char* decla_name = strdup(declarator.value.id_val);
    t_symbol_table* existing_symbol = (t_symbol_table*)get_element(VARIABLE, decla_name, compare_char_and_ID_variable);

    if (!existing_symbol && strcmp(decla_name, data_variable->variable) != 0) { // Hay una funcion del lado izquierdo (no es variable guardada ni se esta inicializando)
        _asprintf(&data_sem_error->msg, "%i:%i: Se requiere un valor-L modificable como operando izquierdo de la asignacion", line, column - 2);
        insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
        return;
    }

    // El lado izquierdo es una variable
    t_variable* var = NULL;
    if (existing_symbol) {
        var = (t_variable*)existing_symbol->data;

        if (is_const(var->type)) { // Actualizar variable de solo lectura
            _asprintf(&data_sem_error->msg, "%i:%i: Asignacion de la variable de solo lectura '%s'", 
            line, column - 2, var->variable);
            insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
            return;
        }

    } else {
         var = malloc(sizeof(t_variable)); 
        if (var == NULL) {
            perror("Error al asignar memoria");
            return;
        }
        // Si llego hasta aca y existing_symbol es NULL, entonces se esta inicializando y data_variable->variable == decla_name
        var->type = strdup(data_variable->type);
        var->variable = strdup(data_variable->variable);
    }
    
    const char* expected_type = var->type; // Tipo a verificar con el lado derecho

    if (is_const(expected_type)) {
        expected_type = get_base_type(var->type);
    }

    switch (initializer.type) {
        case ID: {
            char* init_name = strdup(initializer.value.id_val);

            t_symbol_table* aux = (t_symbol_table*)get_element(VARIABLE, init_name, compare_char_and_ID_variable);
            if (aux) { // El lado derecho es una variable
                t_variable* init = (t_variable*)aux->data;
                if (check_type_match(init->type, expected_type) == 0) {
                    _asprintf(&data_sem_error->msg, "%i:%i: Incompatibilidad de tipos al inicializar el tipo '%s' usando el tipo '%s'", 
                    line, column, expected_type, init->type);
                    insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
                    return;
                }
            } else { 
                aux = (t_symbol_table*)get_element(FUNCTION, init_name, compare_char_and_ID_function);
                if (!aux) {
                    if (fetch_parameter(init_name)) { // El lado derecho es un parametro
                        t_parameter* param = get_param(init_name); 
                        if (check_type_match(param->type, expected_type) == 0) {
                            _asprintf(&data_sem_error->msg, "%i:%i: Incompatibilidad de tipos al inicializar el tipo '%s' usando el tipo '%s'", 
                            line, column, expected_type, param->type);
                            insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
                            return;
                        }
                    }
                    return;
                } // El lado derecho es una funcion
                t_function* init = (t_function*)aux->data;
                char* parameters_concat = concat_parameters(init->parameters);
                if (check_type_match(init->return_type, expected_type) == 0) {
                    _asprintf(&data_sem_error->msg, "%i:%i: Incompatibilidad de tipos al inicializar el tipo '%s' usando el tipo '%s (*)(%s)'", 
                    line, column, expected_type, init->return_type, parameters_concat);
                    insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
                    return;
                }
            }
            break;
        }

        default: {
            char* init_type = type_to_string(initializer.type);

            if (check_type_match(init_type, expected_type) == 0) {
                _asprintf(&data_sem_error->msg, "%i:%i: Incompatibilidad de tipos al inicializar el tipo '%s' usando el tipo '%s'", 
                line, column, expected_type, init_type);
                insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
                return;
            }
            break;
        }
    }
}

int is_const(const char* type) {
    return strncmp(type, "const ", 6) == 0;
}

int check_type_match(const char* a, const char* b) { // Mejorar para que reconozca tipos compatibles
    const char* baseA = get_base_type(a);
    const char* baseB = get_base_type(b);
    
    if (strcmp(baseA, baseB) == 0) {
        return 1; 
    }
    
    if ((strcmp(baseA, "float") == 0 && strcmp(baseB, "double") == 0) ||
        (strcmp(baseA, "double") == 0 && strcmp(baseB, "float") == 0)) {
        return 1; 
    }

    if ((strcmp(baseA, "int") == 0 && strcmp(baseB, "long") == 0) ||
        (strcmp(baseA, "long") == 0 && strcmp(baseB, "int") == 0)) {
        return 1; 
    }

    if ((strcmp(baseA, "int") == 0 && strcmp(baseB, "short") == 0) ||
        (strcmp(baseA, "short") == 0 && strcmp(baseB, "int") == 0)) {
        return 1; 
    }

    return 0;
}

const char* get_base_type(const char* type) { // Devuelve la ultima palabra del tipo para facilitar comparaciones
    char* type_copy = strdup(type);
    if (type_copy == NULL) {
        perror("Error al asignar memoria");
        return NULL;
    }

    // Dividir la cadena en tokens
    char* token = strtok(type_copy, " ");
    const char* base_type = NULL;

    // Iterar a través de los tokens y guardar el último token
    while (token != NULL) {
        base_type = token;
        token = strtok(NULL, " ");
    }

    char* result = strdup(base_type);
    if (result == NULL) {
        perror("Error al asignar memoria");
        free(type_copy);
        return NULL;
    }

    free(type_copy);

    return result;
}

void check_multiplication (t_variable_value left_side, t_variable_value right_side, int line, int column) {
    // Vamos a chequear que los tipos de los operandos de la multiplicación sean válidos
    
    bool left_correct, right_correct;
    char* left_type;
    char* right_type;

    if (left_side.type == ID) {

        left_type = find_id_type(left_side.value.id_val, line, column);
        left_correct = check_multiplication_aux_ids(left_type);        
    } else{

        left_correct = check_multiplication_aux_enums(left_side.type);
        left_type = type_to_string(left_side.type);
    }
    
    if (right_side.type == ID) { 
        right_type = find_id_type(right_side.value.id_val, line, column);
        right_correct = check_multiplication_aux_ids(right_type);
        
    } else{
        right_correct = check_multiplication_aux_enums(right_side.type);
        right_type = type_to_string(right_side.type);
    }

    if(!(left_correct && right_correct)){

        _asprintf(&data_sem_error->msg, "%i:%i: Operandos invalidos del operador binario * (tienen \'%s\' y \'%s\')", line, column, left_type, right_type);
        insert_node(&semantic_errors, data_sem_error, sizeof(t_semantic_error));
        return;
    }    
}

bool check_multiplication_aux_enums(TYPES type){
    switch(type){
        case STRING:
        case UNKNOWN:
            return false;
            break;
        case NUMBER:
        case INT:
            return true;
            break;
        default:
            return false;
            break;
    }
}

bool check_multiplication_aux_ids(char* type) {
    if (strcmp(type, "float") == 0 || strcmp(type, "int") == 0 ||
        strcmp(type, "double") == 0 || strcmp(type, "short") == 0 ||
        strcmp(type, "long") == 0 || strcmp(type, "unsigned") == 0 ||
        strcmp(type, "signed") == 0 || strcmp(type, "unsigned int") == 0 ||
        strcmp(type, "unsigned long") == 0 || strcmp(type, "signed int") == 0 ||
        strcmp(type, "short int") == 0 || strcmp(type, "signed short int") == 0 ||
        strcmp(type, "unsigned short int") == 0 || strcmp(type, "long int") == 0 ||
        strcmp(type, "signed long int") == 0 || strcmp(type, "const float") == 0) {
        return true;
    } else if (strcmp(type, "char") == 0 || strcmp(type, "void") == 0 ||
               strcmp(type, "char*") == 0 || strcmp(type, "void (*)(void)") == 0) {
        return false;
    } else {
        return false;
    }
}

char* find_id_type(char* id, int line, int column) {
    t_symbol_table* existing_symbol = (t_symbol_table*)get_element(VARIABLE, id, compare_char_and_ID_variable);
    t_symbol_table* existing_function = (t_symbol_table*)get_element(FUNCTION, id, compare_char_and_ID_function);

    if(existing_symbol){
        t_variable* identificador = (t_variable*)existing_symbol->data;
        return identificador->type;
    } else if(existing_function){
        t_function* identificador = (t_function*)existing_function->data;
        int quant = get_quantity_parameters(identificador->parameters);
        if(quant == 0){
            char* tipo_compuesto = concat_types(identificador->return_type);
            return tipo_compuesto;
        }
        return identificador->return_type;
    }
    else {
        printf("Error en multiplicación, line: %d, column: %d \n", line, column);
        return NULL;
    }
}

char* concat_types(char* return_type) {
    const char* ending_type = " (*)(void)";
    
    size_t len_return_type = strlen(return_type);
    size_t len_ending_type = strlen(ending_type);
    
    char* tipo_compuesto = (char*) malloc((len_return_type + len_ending_type + 1) * sizeof(char));

    if (tipo_compuesto == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    strcpy(tipo_compuesto, return_type);
    strcat(tipo_compuesto, ending_type);

    return tipo_compuesto;
}

char* concat_strings(const char* string1, const char* string2) {
    // Calcula el tamaño necesario para la cadena concatenada
    size_t len1 = string1 ? strlen(string1) : 0;
    size_t len2 = string2 ? strlen(string2) : 0;
    char* result = malloc(len1 + len2 + 2);  // +2 para el carácter nulo y espacio

    if (result == NULL) {
        fprintf(stderr, "Error de asignación de memoria.\n");
        exit(1);
    }

    result[0] = '\0';

    if (string1) strcpy(result, string1);
    if (string1 && string2) strcat(result, " ");
    if (string2) strcat(result, string2);

    return result;
}