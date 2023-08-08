#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------------------------------------------------------------------- //

// Define max lengths
#define MAX_VEHICLES 80
#define MAX_PLATE_LENGTH 8
#define MAX_BRAND_LENGTH 20
#define MAX_MODEL_LENGTH 20
#define MAX_TYPE_LENGTH 6
#define MAX_OBS_LENGTH 100

// System constants
#define TYPE_MOTORCYCLE 0
#define TYPE_CAR 1
#define DEFAULT_FILE "data.txt"

// --------------------------------------------------------------------------------------- //

// Structs
typedef struct {
    char plate[MAX_PLATE_LENGTH];
    char brand[MAX_BRAND_LENGTH];
    char model[MAX_MODEL_LENGTH];
    int year;
    float price;
    int type;
    char obs[MAX_OBS_LENGTH];
} Vehicle;

// --------------------------------------------------------------------------------------- //

// Global variables
Vehicle vehicles[MAX_VEHICLES];
int vehiclesCount = 0;
int mainMenuOption = -1;

// --------------------------------------------------------------------------------------- //

// Functions
char *getTypeStr(int type) {

    if (type == TYPE_MOTORCYCLE) return "moto";
    else if (type == TYPE_CAR) return "carro";
    return "N/A";
}

// --------------------------------------------------------------------------------------- //

// Prototypes
void printVehicle(Vehicle vehicle) {

    printf("Placa: %s\n", vehicle.plate);
    printf("Marca: %s\n", vehicle.brand);
    printf("Modelo: %s\n", vehicle.model);
    printf("Ano: %d\n", vehicle.year);
    printf("Preco: %.2f\n", vehicle.price);
    printf("Tipo: %s\n", getTypeStr(vehicle.type));
    printf("Observacoes: %s\n", vehicle.obs);
}

void loadVehiclesFile() {

    FILE *file = fopen(DEFAULT_FILE, "r");

    if (file == NULL) {

        printf("x Error while opening file.\n");
        exit(1);
    }

    // ------------------------------------- //

    char plate[MAX_PLATE_LENGTH];
    char brand[MAX_BRAND_LENGTH];
    char model[MAX_MODEL_LENGTH];
    int year;
    float price;
    char type_str[MAX_TYPE_LENGTH]; int type;
    char obs[MAX_OBS_LENGTH];

    fscanf(file, "%d\n", &vehiclesCount);

    for (int i = 0; i < vehiclesCount; i++) {

        Vehicle *vehicle = (Vehicle *) malloc(sizeof(Vehicle));

        fscanf(file, "%[^;];%[^;];%[^;];%d;%f;%[^;];%[^\n]\n", plate, brand, model, &year, &price, type_str, obs);

        strcpy(vehicle -> plate, plate);        
        strcpy(vehicle -> brand, brand);
        strcpy(vehicle -> model, model);
        strcpy(vehicle -> obs, obs);
        
        vehicle -> year = year;
        vehicle -> price = price;

        if (!strcmp(type_str, "moto")) vehicle -> type = TYPE_MOTORCYCLE;
        else if (!strcmp(type_str, "carro")) vehicle -> type = TYPE_CAR;
        else vehicle -> type = -1;

        // ------------------------------------- //

        vehicles[i] = *vehicle;

        free(vehicle);
    }

    fclose(file);
}

void updateVehiclesFile() {

    FILE *file = fopen(DEFAULT_FILE, "w");

    if (file == NULL) {

        printf("x Error while opening file.\n");
        exit(1);
    }

    // ------------------------------------- //

    // Clean file
    fprintf(file, "%d\n", vehiclesCount);

    for (int i = 0; i < vehiclesCount; i++) {

        fprintf(file, "%s;%s;%s;%d;%.2f;%s;%s\n", vehicles[i].plate, vehicles[i].brand, vehicles[i].model, vehicles[i].year, vehicles[i].price, getTypeStr(vehicles[i].type), vehicles[i].obs);
    }

    fclose(file);
}

// --------------------------------------------------------------------------------------- //

int main() {

    loadVehiclesFile();

    do
    {
        printf("\nMENU DE OPCOES\n\n");
        printf("[1] Listar todos os veiculos\n");
        printf("[2] Pesquisar um veiculo\n");
        printf("[3] Cadastrar um veiculo\n");
        printf("[4] Editar um veiculo\n");
        printf("[5] Excluir um veiculo\n");
        printf("[0] SAIR\n");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &mainMenuOption);
        
        // ------------------------------- //

        switch(mainMenuOption) {

            case 1: {

                printf("\nLISTA DE VEICULOS\n\n");

                for (int i = 0; i < vehiclesCount; i++) {

                    printf("Veiculo %d\n", i + 1);
                    printVehicle(vehicles[i]);
                    printf("\n");
                }
                break;
            }

            // ------------------------------- //

            case 2: {

                char plate[MAX_PLATE_LENGTH];
                printf("\nDigite a placa do veiculo: ");
                scanf("%s", plate);

                int found = 0;

                for (int i = 0; i < vehiclesCount; i++) {

                    if (!strcmp(vehicles[i].plate, plate)) {

                        printf("\n[i] Veiculo encontrado!\n\n");
                        printVehicle(vehicles[i]);
                        found = 1;
                        break;
                    }
                }

                if(!found) printf("\n[x] Veiculo nao encontrado!\n");
                break;
            }

            // ------------------------------- //
            
            case 3: {

                Vehicle *vehicle = (Vehicle *) malloc(sizeof(Vehicle));

                printf("\nCADASTRO DE VEICULO\n\n");
                
                strcpy(vehicle -> plate, "N/A");

                // Repeat until plate isn't N/A or already exists
                while (!strcmp(vehicle -> plate, "N/A")) {

                    printf("Digite a placa do veiculo: ");
                    scanf("%s", vehicle -> plate);

                    for (int i = 0; i < vehiclesCount; i++) {

                        if (!strcmp(vehicles[i].plate, vehicle -> plate)) {

                            printf("\n[x] Placa ja cadastrada!\n");
                            strcpy(vehicle -> plate, "N/A");
                            break;
                        }
                    }
                }

                printf("Digite a marca do veiculo: ");
                scanf(" %[^\n]s", vehicle -> brand);

                printf("Digite o modelo do veiculo: ");
                scanf(" %[^\n]s", vehicle -> model);

                printf("Digite o ano do veiculo: ");
                scanf("%d", &vehicle -> year);

                printf("Digite o preco do veiculo: ");
                scanf("%f", &vehicle -> price);

                printf("Digite o tipo do veiculo (moto ou carro): ");
                scanf(" %[^\n]s", vehicle -> obs);

                if (!strcmp(vehicle -> obs, "moto")) vehicle -> type = TYPE_MOTORCYCLE;
                else if (!strcmp(vehicle -> obs, "carro")) vehicle -> type = TYPE_CAR;
                else vehicle -> type = -1;

                printf("Digite as observacoes do veiculo: ");
                scanf("%s", vehicle -> obs);

                // ------------------------------- //

                vehicles[vehiclesCount] = *vehicle;
                vehiclesCount++;

                updateVehiclesFile();

                // ------------------------------- //

                printf("\n[i] Veiculo cadastrado com sucesso!\n");
                break;
            }

            // ------------------------------- //

            case 4: {

                char plate[MAX_PLATE_LENGTH];
                printf("\nDigite a placa do veiculo: ");
                scanf("%s", plate);

                int found = 0;

                for (int i = 0; i < vehiclesCount; i++) {

                    if (!strcmp(vehicles[i].plate, plate)) {

                        printf("\n[i] Veiculo encontrado!\n\n");
                    
                        found = 1;

                        printf("\nEDITAR VEICULO\n\n");

                        printf("Digite a marca do veiculo: ");
                        scanf(" %[^\n]s", vehicles[i].brand);

                        printf("Digite o modelo do veiculo: ");
                        scanf(" %[^\n]s", vehicles[i].model);

                        printf("Digite o ano do veiculo: ");
                        scanf("%d", &vehicles[i].year);

                        printf("Digite o preco do veiculo: ");
                        scanf("%f", &vehicles[i].price);

                        printf("Digite o tipo do veiculo (moto ou carro): ");
                        scanf(" %[^\n]s", vehicles[i].obs);

                        if (!strcmp(vehicles[i].obs, "moto")) vehicles[i].type = TYPE_MOTORCYCLE;
                        else if (!strcmp(vehicles[i].obs, "carro")) vehicles[i].type = TYPE_CAR;
                        else vehicles[i].type = -1;

                        printf("Digite as observacoes do veiculo: ");
                        scanf("%s", vehicles[i].obs);

                        updateVehiclesFile();

                        printf("\n[i] Veiculo editado com sucesso!\n");
                        break;
                    }
                }

                if(!found) printf("\n[x] Veiculo nao encontrado!\n");
                break;
            }

            // ------------------------------- //

            case 5: {

                char plate[MAX_PLATE_LENGTH];
                printf("\nDigite a placa do veiculo: ");
                scanf("%s", plate);

                int found = 0;

                for (int i = 0; i < vehiclesCount; i++) {

                    if (!strcmp(vehicles[i].plate, plate)) {

                        printf("\n[i] Veiculo encontrado!\n\n");
                    
                        found = 1;

                        for (int j = i; j < vehiclesCount - 1; j++) {

                            vehicles[j] = vehicles[j + 1];
                        }

                        vehiclesCount--;

                        updateVehiclesFile();

                        printf("\n[i] Veiculo excluido com sucesso!\n");
                        break;
                    }
                }

                if(!found) printf("\n[x] Veiculo nao encontrado!\n");
                break;
            }
        }
    }
    while(mainMenuOption != 0);
    
    return 0;
}