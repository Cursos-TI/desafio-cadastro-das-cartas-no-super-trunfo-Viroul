//ESTE CODIOGO É APENAS UM TESTE QUE EU TENTEI FAZER SEM SEGUIR AS REGRAS ESTABELECIDAS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct Carta {
    char Estado_nome[8][50];         // Nome do estado (máximo de 8 estados)
    char cidades[8][4][50];          // Até 4 cidades por estado
    int populacao[8][4];             // População de cada cidade
    float area[8][4];                // Área de cada cidade
    double PIB[8][4];                // PIB da cidade
    int pontos_turisticos[8][4];     // Pontos turísticos da cidade
    int num_estados;                 // Quantidade de estados cadastrados
    int cidades_por_estado[8];       // Quantidade de cidades cadastradas por estado
    int estado_atual;                // Índice do estado atual
};

// Gera o código para um estado e uma cidade
void gerar_codigo(char *codigo, int estado_index, int cidade_index) {
    sprintf(codigo, "%c%02d", 'A' + estado_index, cidade_index + 1);
}

// Verifica se o estado já existe
int estado_existente(struct Carta *verificar_estado, const char *estado_nome) {
    // Verifica se o estado já foi cadastrado
    for (int i = 0; i < verificar_estado->num_estados; i++) {
        if (strcmp(verificar_estado->Estado_nome[i], estado_nome) == 0) {
            verificar_estado->estado_atual = i;  // Define o índice do estado existente como o atual
            return 1;  // Estado encontrado
        }
    }
    return 0;  // Estado não encontrado
}

// Verifica se a cidade já existe
int cidade_existente(struct Carta *verificar_cidade, const char *cidade_nome) {
    // Verifica se a cidade já foi cadastrada em algum estado
    for (int i = 0; i < verificar_cidade->num_estados; i++) {
        for (int j = 0; j < verificar_cidade->cidades_por_estado[i]; j++) {
            if (strcmp(verificar_cidade->cidades[i][j], cidade_nome) == 0) {
                return 1; // Cidade já existe
            }
        }
    }
    return 0; // Cidade não encontrada
}

// Cadastro de um estado
void adicionar_estado(struct Carta *Dados_do_estado) {
    // Limite de estados atingido
    if (Dados_do_estado->num_estados >= 8) {
        printf("Limite de estados atingido\n");
        return;
    }

    char estado_nome[50];
    
    printf("\n----Cadastre um novo estado ou Atualize um estado existente----\n");
    while (1) {
        printf("\nDigite o nome do Estado: ");
        scanf(" %49[^\n]", estado_nome);
        
        // Verificar se o estado já foi cadastrado
        if (estado_existente(Dados_do_estado, estado_nome)) {
            printf("Estado já cadastrado. Deseja adicionar uma nova cidade? (S/N): ");
            char resposta;
            scanf(" %c", &resposta);
            resposta = toupper(resposta);
            if (resposta == 'S') {
                break; 
            }
        } else {
            // Adiciona o nome do estado à lista
            strcpy(Dados_do_estado->Estado_nome[Dados_do_estado->num_estados], estado_nome);
            Dados_do_estado->cidades_por_estado[Dados_do_estado->num_estados] = 0; // Inicializa o contador de cidades para este estado
            Dados_do_estado->num_estados++;
            Dados_do_estado->estado_atual = Dados_do_estado->num_estados - 1; // Atualiza o estado atual
            break;
        }
    }
}

// Cadastro de uma cidade
void adicionar_cidade(struct Carta *Dados_da_cidade) {
    if (Dados_da_cidade->cidades_por_estado[Dados_da_cidade->estado_atual] >= 4) {
        printf("Limite de cidades para este estado atingido.\n");
        return;
    }
    
    char cidade_nome[50];
    
    while (1) {
        printf("Digite o nome da Cidade: ");
        scanf(" %49[^\n]", cidade_nome);

        // Verifica se a cidade já foi cadastrada
        if (cidade_existente(Dados_da_cidade, cidade_nome)) {
            printf("Cidade já existente. Crie outra cidade.\n");
        } else {
            break; // Cidade válida
        }
    }
    
    // Adiciona a cidade à lista do estado atual
    int cidade_index = Dados_da_cidade->cidades_por_estado[Dados_da_cidade->estado_atual];
    strcpy(Dados_da_cidade->cidades[Dados_da_cidade->estado_atual][cidade_index], cidade_nome);
    Dados_da_cidade->cidades_por_estado[Dados_da_cidade->estado_atual]++;
    
    // Solicita os dados adicionais da cidade
    printf("Digite a População (exemplo: 12324): ");
    scanf(" %d", &Dados_da_cidade->populacao[Dados_da_cidade->estado_atual][cidade_index]);

    printf("Digite a Área em km² (exemplo: 1000.25): ");
    scanf(" %f", &Dados_da_cidade->area[Dados_da_cidade->estado_atual][cidade_index]);

    printf("Digite o PIB (exemplo: 214453.00): ");
    scanf(" %lf", &Dados_da_cidade->PIB[Dados_da_cidade->estado_atual][cidade_index]);

    printf("Digite os Pontos turísticos (exemplo: 5): ");
    scanf(" %d", &Dados_da_cidade->pontos_turisticos[Dados_da_cidade->estado_atual][cidade_index]);

    // Mostrar os detalhes da cidade cadastrada
    char codigo[4];
    gerar_codigo(codigo, Dados_da_cidade->estado_atual, cidade_index);
    printf("\nDetalhes da cidade cadastrada\n");
    printf("  Código: %s\n", codigo);
    printf("  Estado: %s\n", Dados_da_cidade->Estado_nome[Dados_da_cidade->estado_atual]);
    printf("  Cidade: %s\n", Dados_da_cidade->cidades[Dados_da_cidade->estado_atual][cidade_index]);
    printf("  População: %d\n", Dados_da_cidade->populacao[Dados_da_cidade->estado_atual][cidade_index]);
    printf("  Área: %.2f km²\n", Dados_da_cidade->area[Dados_da_cidade->estado_atual][cidade_index]);
    printf("  PIB: %.2lf\n", Dados_da_cidade->PIB[Dados_da_cidade->estado_atual][cidade_index]);
    printf("  Pontos turísticos: %d\n", Dados_da_cidade->pontos_turisticos[Dados_da_cidade->estado_atual][cidade_index]);

    printf("Cidade cadastrada com sucesso!\n");
    // Exibe o total de estados cadastrados
    printf("Total de estados cadastrados: %d\n", Dados_da_cidade->num_estados);
    printf("----------------------------------");
}

int main() {
    struct Carta Especificacoes_da_Carta = {0}; // Inicializando a struct com valores padrão
    int parar = 1;

    while (parar == 1) {
        // Cadastro de um estado
        adicionar_estado(&Especificacoes_da_Carta);

        // Cadastro de uma cidade para o estado cadastrado
        adicionar_cidade(&Especificacoes_da_Carta);  

        // Pergunta se deseja continuar
        printf("\nDeseja continuar o cadastro? (1 - Sim, 0 - Não): ");
        scanf("%d", &parar);

    }
    return 0;
}
