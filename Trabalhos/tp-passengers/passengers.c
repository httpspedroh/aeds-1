/**
 * Passengers Management System
 *
 * @file passenger.c
 * @brief Functions for passengers management
 * @version 1.0
 * @date 6/22/2023
 * @details This script read and explode "data.txt" file, and save the data in a struct
 * 
**/

// --------------------------------------------------------------------------------------------------- //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// --------------------------------------------------------------------------------------------------- //

// Max length of each field
#define MAX_ID_SIZE 5
#define MAX_NAME_SIZE 100
#define MAX_CPF_SIZE 15
#define MAX_ADDRESS_SIZE 100
#define MAX_PHONE_SIZE 15
#define MAX_TICKET_SIZE 7
#define MAX_SEAT_SIZE 4
#define MAX_FLIGHT_SIZE 6
#define MAX_TIME_SIZE 6
#define MAX_LINE_SIZE 150

// Attributes
#define DEFAULT_FILE "data.txt"
#define MAX_ROUTES 3
#define MAX_PASSENGERS_PER_ROUTE 10
#define MAX_QUEUE_PER_ROUTE 5

// Routes
#define BH_RIO 0
#define BH_SP 1
#define BH_BRASILIA 2

// --------------------------------------------------------------------------------------------------- //

// Passenger struct
typedef struct Passenger {

    int id;
    char name[MAX_NAME_SIZE];
    char cpf[MAX_CPF_SIZE];
    char address[MAX_ADDRESS_SIZE];
    char phone[MAX_PHONE_SIZE];
    int ticket;
    char seat[MAX_SEAT_SIZE];
    int flight;
    char time[MAX_TIME_SIZE];
} Passenger;

// Global variables
Passenger passengers[MAX_ROUTES][MAX_PASSENGERS_PER_ROUTE];
Passenger queue[MAX_ROUTES][MAX_QUEUE_PER_ROUTE];
int count_passengers[3] = {0, 0, 0};
int count_queue[3] = {0, 0, 0};
int global_id = -1;
int mainMenuOption = -1;
int subMenuOption = -1;

// --------------------------------------------------------------------------------------------------- //

// Function prototypes
void print_passenger(Passenger passenger) {

    printf("ID: %d\n", passenger.id);
    printf("Nome: %s\n", passenger.name);
    printf("CPF: %s\n", passenger.cpf);

    if(strcmp(passenger.address, "N/A")) printf("Endereço: %s\n", passenger.address);
    if(strcmp(passenger.phone, "N/A")) printf("Telefone: %s\n", passenger.phone);

    printf("N° Passagem: %d\n", passenger.ticket);

    if(strcmp(passenger.seat, "N/A")) printf("N° Poltrona: %s\n", passenger.seat);
    if(passenger.flight != -1) printf("N° Voo: %d\n", passenger.flight);
    if(strcmp(passenger.time, "N/A")) printf("Horário: %s\n", passenger.time);
}

// --------------------------------------------------------------------------------------------------- //

void read_file() {

    // Open file
    FILE *file = fopen(DEFAULT_FILE, "r");

    // Check if file exists
    if (file == NULL) {

        printf("x Error: Cannot open file \"%s\"!\n", DEFAULT_FILE);
        exit(1);
    }

    // ----------------------------------- //

    char line[MAX_LINE_SIZE];

    while (fgets(line, sizeof(line), file) != NULL) {

        if (strstr(line, "ID: ") != NULL) {

            int route;

            Passenger *passenger = (Passenger*)malloc(sizeof(Passenger));

            // ----------------------------------- //

            // Get ID with sscanf
            sscanf(line, "ID: %d", &passenger -> id);

            global_id = passenger -> id;

            // Get Name with sscanf
            fgets(line, sizeof(line), file);
            sscanf(line, "Nome Completo: %[^\n]", passenger -> name);

            // Get CPF with sscanf
            fgets(line, sizeof(line), file);
            sscanf(line, "CPF: %s", passenger -> cpf);

            // ----------------------------------- //

            // Check if passenger has address and phone
            fgets(line, sizeof(line), file);

            if (strstr(line, "Endereço: ") != NULL) {

                // Get Address with sscanf
                sscanf(line, "Endereço: %[^\n]", passenger -> address);

                // Get Phone with sscanf
                fgets(line, sizeof(line), file);
                sscanf(line, "Telefone: %[^\n]", passenger -> phone);
                fgets(line, sizeof(line), file);
            }
            else {
                
                strcpy(passenger -> address, "N/A");
                strcpy(passenger -> phone, "N/A");
            }

            // ----------------------------------- //

            // Get Ticket with sscanf
            sscanf(line, "N° PASSAGEM: %d", &passenger -> ticket);

            // Get route with first 2 digits of ticket. 11 = BH > SP, 21 = BH > Rio, 61 = BH > Brasilia
            int tmp = passenger -> ticket / 10000;

            if (tmp == 11) route = BH_SP;
            else if (tmp == 21) route = BH_RIO;
            else if (tmp == 61) route = BH_BRASILIA;

            // ----------------------------------- //

            // Check if passenger has seat
            fgets(line, sizeof(line), file);

            if (strstr(line, "N° POLTRONA: ") != NULL) {

                // Get Seat with sscanf
                if(strlen(line) > 13 + 3) sscanf(line, "N° POLTRONA: %s", passenger -> seat);
                else strcpy(passenger -> seat, "N/A");

                fgets(line, sizeof(line), file);
            }
            else strcpy(passenger -> seat, "N/A");

            // ----------------------------------- //

            // Check if passenger has flight
            if (strstr(line, "N° VOO: ") != NULL) {

                // Get Flight with sscanf
                if(strlen(line) > 8 + 3) sscanf(line, "N° VOO: %d", &passenger -> flight);
                else passenger -> flight = -1;

                fgets(line, sizeof(line), file);
            }
            else passenger -> flight = -1;

            // ----------------------------------- //

            // Check if passenger has time
            if (strstr(line, "Horário: ") != NULL) {

                // Get Time with sscanf
                if(strlen(line) > 9 + 3) sscanf(line, "Horário: %s", passenger -> time);
                else strcpy(passenger -> time, "N/A");

                if (strstr(line, "ID: ") != NULL) fgets(line, sizeof(line), file);
            }
            else strcpy(passenger -> time, "N/A");

            // ----------------------------------- //
    
            // Add passenger to array
            if(passenger -> flight == -1) {

                queue[route][count_queue[route]] = *passenger;
                count_queue[route]++;
            }
            else {

                passengers[route][count_passengers[route]] = *passenger;
                count_passengers[route]++;
            }

            // ----------------------------------- //

            // Free memory
            free(passenger);
        }
    }

    // ----------------------------------- //

    // Close file
    fclose(file);
}

// --------------------------------------------------------------------------------------------------- //

// Menu functions
char *get_route_name(int route) {

    switch(route) {

        case BH_RIO: return "BH > RIO";
        case BH_SP: return "BH > SP";
        case BH_BRASILIA: return "BH > BRASÝLIA";
    }
    return "N/A";
}

// --------------------------------------------------------------------------------------------------- //

void show_passengers() {

    int route = mainMenuOption - 1;

    printf("\n-------------------------------------------\n");
    printf("\nEMPRESA AÉREA QUEDA LIVRE - VOO: %s\n\n", get_route_name(route));
    printf("-> LISTA GERAL DE PASSAGEIROS\n\n");

    if(count_passengers[route] == 0) printf("[!] Não há passageiros na lista!\n\n");
    else {

        for(int i = 0; i < count_passengers[route]; i++) {

            print_passenger(passengers[route][i]);

            printf("%s", i < count_passengers[route] - 1 ? "\n" : "");
        }
    }

    subMenuOption = -1;
}

void show_passengers_queue() {

    int route = mainMenuOption - 1;

    printf("\n-------------------------------------------\n");
    printf("\nEMPRESA AÉREA QUEDA LIVRE - VOO: %s\n\n", get_route_name(route));
    printf("-> LISTA DE ESPERA\n\n");

    if(count_queue[route] == 0) printf("[!] Não há passageiros na lista de espera!\n\n");
    else {

        for(int i = 0; i < count_queue[route]; i++) {

            print_passenger(queue[route][i]);

            printf("%s", i < count_queue[route] - 1 ? "\n" : "");
        }
    }

    subMenuOption = -1;
}

// --------------------------------------------------------------------------------------------------- //

void search_passenger_by_cpf() {

    int route = mainMenuOption - 1;
    char cpf[MAX_CPF_SIZE];
    int found = 0;

    printf("\n-------------------------------------------\n");
    printf("\nEMPRESA AÉREA QUEDA LIVRE - VOO: %s\n\n", get_route_name(route));
    printf("-> BUSCAR PASSAGEIRO\n\n");

    printf("Digite o CPF do passageiro: ");
    scanf("%s", cpf);

    // Search in passenger and queue
    for(int i = 0; i < count_passengers[route]; i++) {

        if(strcmp(passengers[route][i].cpf, cpf) == 0) {

            printf("\n[!] Passageiro encontrado na lista geral!\n\n");

            print_passenger(passengers[route][i]);

            found = 1;
            break;
        }
    }

    if(!found) {

        for(int i = 0; i < count_queue[route]; i++) {

            if(strcmp(queue[route][i].cpf, cpf) == 0) {

                printf("\n[!] Passageiro encontrado na lista de espera!\n\n");

                print_passenger(queue[route][i]);
                found = 1;
                break;
            }
        }
    }

    if(!found) printf("\n[x] Passageiro não consta neste vôo!\n");
}

// --------------------------------------------------------------------------------------------------- //

void search_passenger_by_name() {

    int route = mainMenuOption - 1;
    char name[MAX_NAME_SIZE];
    int found = 0;

    printf("\n-------------------------------------------\n");
    printf("\nEMPRESA AÉREA QUEDA LIVRE - VOO: %s\n\n", get_route_name(route));
    printf("-> BUSCAR PASSAGEIRO\n\n");

    printf("Digite o nome do passageiro: ");
    scanf(" %[^\n]s", name);

    // Search in passenger and queue
    for(int i = 0; i < count_passengers[route]; i++) {

        if(!strcmp(passengers[route][i].name, name)) {

            printf("\n[!] Passageiro encontrado na lista geral!\n\n");

            print_passenger(passengers[route][i]);
            found = 1;
            break;
        }
    }

    if(!found) {

        for(int i = 0; i < count_queue[route]; i++) {

            if(strcmp(queue[route][i].name, name) == 0) {

                printf("\n[!] Passageiro encontrado na lista de espera!\n\n");

                print_passenger(queue[route][i]);
                found = 1;
                break;
            }
        }
    }

    if(!found) printf("\n[x] Passageiro não consta neste vôo!\n");
}

// --------------------------------------------------------------------------------------------------- //

void add_passenger_to_file(Passenger passenger) {

    FILE *file = fopen(DEFAULT_FILE, "a");

    if(file == NULL) {

        printf("x Error: Cannot open file \"%s\"!\n", DEFAULT_FILE);
        return;
    }

    // ----------------------------------- //
    
    // Check if last line isn't an \n
    fseek(file, -1, SEEK_END);

    if(fgetc(file) != '\n') fprintf(file, "\n");
    
    // Write passenger to file
    fprintf(file, "\nID: %d\n", passenger.id);
    fprintf(file, "Nome Completo: %s\n", passenger.name);
    fprintf(file, "CPF: %s\n", passenger.cpf);
    fprintf(file, "Endereço: %s\n", passenger.address);
    fprintf(file, "Telefone: %s\n", passenger.phone);
    fprintf(file, "N° PASSAGEM: %d\n", passenger.ticket);
    fprintf(file, "N° POLTRONA: %s\n", passenger.seat);
    fprintf(file, "N° VOO: %d\n", passenger.flight);
    fprintf(file, "Horário: %s", passenger.time);

    fclose(file);
}

// --------------------------------------------------------------------------------------------------- //

void delete_passenger_from_file(int id) {

    FILE *file = fopen(DEFAULT_FILE, "r");

    if(file == NULL) {

        printf("x Error: Cannot open file \"%s\"!\n", DEFAULT_FILE);
        return;
    }

    // ----------------------------------- //

    FILE *temp_file = fopen("temp.txt", "w");

    if(temp_file == NULL) {

        printf("x Error: Cannot open file \"%s\"!\n", DEFAULT_FILE);
        return;
    }

    // ----------------------------------- //

    char line[MAX_LINE_SIZE];
    int found = 0;

    while(fgets(line, MAX_LINE_SIZE, file) != NULL) {

        if(strstr(line, "ID: ") != NULL) {

            int current_id = atoi(line + 4);

            if(current_id == id) {

                found = 1;

                // Skip passenger until found "ID: " again
                while(fgets(line, MAX_LINE_SIZE, file) != NULL) {

                    if(strstr(line, "ID: ") != NULL) {

                        fprintf(temp_file, "%s", line);   
                        break;
                    }
                }
            }
        }

        if(!found) fprintf(temp_file, "%s", line);
        else found = 0;
    }

    // ----------------------------------- //

    fclose(file);
    fclose(temp_file);

    remove(DEFAULT_FILE);
    rename("temp.txt", DEFAULT_FILE);
}

// --------------------------------------------------------------------------------------------------- //

void add_passenger() {

    int route = mainMenuOption - 1;

    // ----------------------------------- //

    // Check if list is full
    if(count_passengers[route] >= MAX_PASSENGERS_PER_ROUTE) {

        printf("\n[!] A lista geral está cheia!");

        if(count_queue[route] >= MAX_QUEUE_PER_ROUTE) {
            
            printf("\n[x] A lista de espera está cheia, não é possível adicionar mais passageiros!\n");

            subMenuOption = -1;
            return;
        }
        else printf("\n[i] O passageiro será adicionado à lista de espera!\n");
    }

    // ----------------------------------- //

    Passenger *new_passenger = (Passenger *) malloc(sizeof(Passenger));

    printf("\n-------------------------------------------\n");
    printf("\nEMPRESA AÉREA QUEDA LIVRE - VOO: %s\n\n", get_route_name(route));
    printf("-> ADICIONAR PASSAGEIRO\n\n");

    // Set ID
    new_passenger -> id = ++global_id;

    // Get name
    printf("Digite o nome do passageiro: ");
    scanf(" %[^\n]s", new_passenger -> name);

    // Get CPF
    printf("Digite o CPF do passageiro: ");
    scanf(" %s", new_passenger -> cpf);

    // Get address
    printf("Digite o endereço do passageiro: ");
    scanf(" %[^\n]s", new_passenger -> address);

    // Get phone
    printf("Digite o telefone do passageiro: ");
    scanf(" %[^\n]s", new_passenger -> phone);

    if(count_passengers[route] >= MAX_PASSENGERS_PER_ROUTE) {

        if(count_queue[route] < MAX_QUEUE_PER_ROUTE) {

            // Set ticket
            int tmp;

            if(route == BH_RIO) tmp = 100000;
            else if(route == BH_SP) tmp = 110000;
            else if(route == BH_BRASILIA) tmp = 610000;

            new_passenger -> ticket = tmp;

            // Set seat
            strcpy(new_passenger -> seat, "N/A");

            // Set flight
            new_passenger -> flight = -1;

            // Set time
            strcpy(new_passenger -> time, "N/A");

            // ----------------------------------- //

            queue[route][count_queue[route]] = *new_passenger;
            count_queue[route]++;
        }
    }
    else {

        // Get last passenger
        Passenger last_passenger = passengers[route][count_passengers[route] - 1];

        // Set ticket
        new_passenger -> ticket = last_passenger.ticket + 1;

        // Set seat
        char tmp[2];

        if(last_passenger.seat[0] == '5') {

            tmp[0] = '1';
            tmp[1] = last_passenger.seat[1] + 1;
        }
        else {

            tmp[0] = last_passenger.seat[0] + 1;
            tmp[1] = last_passenger.seat[1];
        }

        strcpy(new_passenger -> seat, tmp);

        // Set flight
        new_passenger -> flight = last_passenger.flight;

        // Set time
        strcpy(new_passenger -> time, last_passenger.time);

        // ----------------------------------- //

        passengers[route][count_passengers[route]] = *new_passenger;
        count_passengers[route]++;
    }

    // ----------------------------------- //

    printf("\n[OK] Passageiro adicionado!\n");

    // Add passenger to file
    add_passenger_to_file(*new_passenger);

    free(new_passenger);
}

// --------------------------------------------------------------------------------------------------- //'

void delete_passenger() {

    int route = mainMenuOption - 1;

    // ----------------------------------- //

    printf("\n-------------------------------------------\n");
    printf("\nEMPRESA AÉREA QUEDA LIVRE - VOO: %s\n\n", get_route_name(route));
    printf("-> REMOVER PASSAGEIRO\n\n");

    // ----------------------------------- //

    char cpf[MAX_CPF_SIZE];

    printf("Digite o CPF do passageiro: ");
    scanf(" %s", cpf);

    // ----------------------------------- //

    int i, j, found = 0;

    // Search in passengers
    for(i = 0; i < count_passengers[route]; i++) {

        if(strcmp(passengers[route][i].cpf, cpf) == 0) {

            found = 1;

            // ----------------------------------- //

            // Delete passenger from file
            delete_passenger_from_file(passengers[route][i].id);

            // ----------------------------------- //

            // Delete passenger from list
            for(j = i; j < count_passengers[route] - 1; j++) {

                passengers[route][j] = passengers[route][j + 1];
            }

            count_passengers[route]--;

            // ----------------------------------- //

            printf("\n[OK] Passageiro removido da lista geral!\n");

            return;
        }
    }

    // Search in queue
    for(i = 0; i < count_queue[route]; i++) {

        if(strcmp(queue[route][i].cpf, cpf) == 0) {

            found = 1;

            // ----------------------------------- //

            // Delete passenger from file
            delete_passenger_from_file(queue[route][i].id);

            // ----------------------------------- //

            // Delete passenger from list
            for(j = i; j < count_queue[route] - 1; j++) {

                queue[route][j] = queue[route][j + 1];
            }

            count_queue[route]--;

            // ----------------------------------- //

            printf("\n[OK] Passageiro removido da lista de espera!\n");

            return;
        }
    }

    if(!found) printf("\n[x] Passageiro não consta neste vôo!\n");
}

// --------------------------------------------------------------------------------------------------- //

void main() {

    // Read file
    read_file();

    // ----------------------------------- //

    do
    {
        printf("\n-------------------------------------------\n");
        printf("\nEMPRESA AÉREA QUEDA LIVRE\n\n");
        printf("-> ESCOLHA A ROTA\n\n");
        printf("[1] BH > RIO\n");
        printf("[2] BH > SP\n");
        printf("[3] BH > BRASÝLIA\n\n");
        printf("[0] SAIR\n\n");
        printf("Digite a opção desejada: ");

        scanf("%d", &mainMenuOption);

        if(mainMenuOption == 0) {

            printf("\n[<3] Obrigado por utilizar o sistema!\n\n");
            break;
        }

        // ----------------------------------- //

        do
        {
            printf("\n-------------------------------------------\n");
            printf("\nEMPRESA AÉREA QUEDA LIVRE - VOO: %s\n\n", get_route_name(mainMenuOption - 1));
            printf("-> MENU DE OPÇÕES\n\n");
            printf("[1] Mostrar Lista de Passageiros\n");
            printf("[2] Pesquisar Passageiro por CPF\n");
            printf("[3] Pesquisar Passageiro por Nome\n");
            printf("[4] Cadastrar Passageiro\n");
            printf("[5] Excluir Passageiro da Lista\n");
            printf("[6] Mostrar Fila de Espera\n\n");
            printf("[0] VOLTAR\n\n");
            printf("Digite a opção desejada: ");

            scanf("%d", &subMenuOption);

            // ----------------------------------- //

            switch(subMenuOption) {

                case 1: show_passengers(); break;
                case 2: search_passenger_by_cpf(); break;
                case 3: search_passenger_by_name(); break;
                case 4: add_passenger(); break;
                case 5: delete_passenger(); break;
                case 6: show_passengers_queue(); break;

            }
        } 
        while (subMenuOption != 0);
        
    } 
    while (mainMenuOption != 0);
    
    // ----------------------------------- //
}