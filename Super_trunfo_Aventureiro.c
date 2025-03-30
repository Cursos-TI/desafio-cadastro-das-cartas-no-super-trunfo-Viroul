#include <stdio.h>

int main() {
    //VARIAVEIS DA CARTA 1
    char Estado_carta_1;
    char Codigo_carta_1[4];
    char Cidade_carta_1[50];
    int Populacao_carta_1;
    float Area_carta_1;
    float PIB_carta_1;
    int Pontos_turisticos_carta_1;
    float Densidade_populacional_carta_1;
    float PIB_per_capita_carta_1;

    //VARIAVEIS DA CARTA 2
    char Estado_carta_2;
    char Codigo_carta_2[4];
    char Cidade_carta_2[50];
    int Populacao_carta_2;
    float Area_carta_2;
    float PIB_carta_2;
    int Pontos_turisticos_carta_2;
    float Densidade_populacional_carta_2;
    float PIB_per_capita_carta_2;

    // USUARIO INSERE INFORMACOES DA CARTA 1
    printf("======= CADASTRO DA CARTA 1 =======\n\n");
    
    printf("Digite uma letra de 'A' a 'H' para o estado (ex: F): ");
    scanf(" %c", &Estado_carta_1);  // usuario insere o estado

    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%3s", Codigo_carta_1);  // usuario insere o código
    while (getchar() != '\n');  // Limpa o buffer de entrada
    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", Cidade_carta_1);  // usuario insere a cidade

    printf("Digite a população da carta (ex: 1500000): ");
    scanf("%d", &Populacao_carta_1);  // usuario insere um numero longo para a população

    printf("Digite a area da carta (exemplo: 1000.25): ");
    scanf("%f", &Area_carta_1);  // usuario insere um número float para a área

    printf("Digite o PIB da carta (exemplo: 214453.00): ");
    scanf("%f", &PIB_carta_1);  // usuario insere um número float para o PIB

    printf("Digite quantos Pontos turísticos tem a carta (exemplo: 5): ");
    scanf("%d", &Pontos_turisticos_carta_1);  // usuario insere um numero int para pontos turísticos

    // Calculo da densidade populacional e PIB per Capita da Carta 1
    Densidade_populacional_carta_1 = (float)Populacao_carta_1 / Area_carta_1;
    PIB_per_capita_carta_1 = PIB_carta_1 / (float)Populacao_carta_1;


    // USUARIO INSERE INFORMACOES DA CARTA 2
    printf("\n======= CADASTRO DA CARTA 2 =======\n");
    
    printf("Digite uma letra de 'A' a 'H' para o estado (ex: F): ");
    scanf(" %c", &Estado_carta_2);  // usuario insere o estado

    printf("Digite o codigo da carta (ex: A02): ");
    scanf("%3s", Codigo_carta_2);  // usuario insere o código
    while (getchar() != '\n');  // Limpa o buffer de entrada
    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", Cidade_carta_2);  // usuario insere a cidade

    printf("Digite a população da carta (ex: 1500000): ");
    scanf("%d", &Populacao_carta_2);  // usuario insere um numero longo para a população

    printf("Digite a area da carta (exemplo: 2000.25): ");
    scanf("%f", &Area_carta_2);  // usuario insere um número float para a área

    printf("Digite o PIB da carta (exemplo: 224453.00): ");
    scanf("%f", &PIB_carta_2);  // usuario insere um número float para o PIB

    printf("Digite quantos Pontos turísticos tem a carta (exemplo: 5): ");
    scanf("%d", &Pontos_turisticos_carta_2);  // usuario insere um numero int para pontos turísticos

    // Calculo da densidade populacional e PIB per Capita da Carta 2
    Densidade_populacional_carta_2 = (float)Populacao_carta_2 / Area_carta_2;
    PIB_per_capita_carta_2 = PIB_carta_2 / (float)Populacao_carta_2;


    // mostra as informações da Carta 1
    printf("\n======= INFORMAÇÕES DA CARTA 1 =======\n");
    printf("Estado: %c\n", Estado_carta_1);
    printf("Código da Carta: %s\n", Codigo_carta_1);
    printf("Nome da Cidade: %s\n", Cidade_carta_1);
    printf("População: %d\n", Populacao_carta_1);
    printf("Área: %.2f km2\n", Area_carta_1);
    printf("PIB: %.2f\n", PIB_carta_1);
    printf("Pontos Turísticos: %d\n", Pontos_turisticos_carta_1);
    printf("Densidade Populacional: %.2f habitantes por km2\n", Densidade_populacional_carta_1);
    printf("PIB per Capita: %.2f\n", PIB_per_capita_carta_1);

    // mostra as informações da Carta 2
    printf("\n======= INFORMAÇÕES DA CARTA 2 =======\n");
    printf("Estado: %c\n", Estado_carta_2);
    printf("Código da Carta: %s\n", Codigo_carta_2);
    printf("Nome da Cidade: %s\n", Cidade_carta_2);
    printf("População: %d\n", Populacao_carta_2);
    printf("Área: %.2f km2\n", Area_carta_2);
    printf("PIB: %.2f\n", PIB_carta_2);
    printf("Pontos Turísticos: %d\n", Pontos_turisticos_carta_2);
    printf("Densidade Populacional: %.2f habitantes por km2\n", Densidade_populacional_carta_2);
    printf("PIB per Capita: %.2f\n", PIB_per_capita_carta_2);

    return 0;
}