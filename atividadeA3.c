#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <process.h>

typedef struct
{
    char Pnome[30];
    int pAnonascimento;
    float Pgastos;
} Pessoa;

Pessoa Ccadastro();
int Ccadastros(Pessoa *_clienttotalist);
int MenuPrincipal(Pessoa *_clienttotalist, int _clientsize);
void sair();
int mostrarlista(Pessoa *_clienttotalist, int _clientsize);
void Ccremover(Pessoa *_clienttotalist, int _clientsize);
void printcliente(Pessoa *_clienttotalist);
void Clientlist(Pessoa *_clienttotalist, int _clientsize);
int insertionSort(Pessoa *_clienttotalist, int _clientsize);
void ViradaDomes(Pessoa *_clienttotalist, int _clientsize);
void bestcomprador(Pessoa *_clienttotalist, int _clientsize);
void QuantiaPagaPorCliente(Pessoa *_clienttotalist, int _clientsize);
bool reallocPos(Pessoa *_clienttotalist, int _clientsize, int pos);
int procurarArrayName(Pessoa *_clienttotalist, int _clientsize, char name[30]);
void sonolimpo();

int main(void)
{

    Pessoa *clienttotalist = (Pessoa *)calloc(10, sizeof(Pessoa));
    int _clientsize;

    int comeco;
    printf("\nBem vindo a loja de TI do Ale\n");
    printf("--------------------------//--------------------------\n");
    printf("MUITO OBRIGADO PARA NOS ESCOLHER\n");
    printf("--------------------------//--------------------------\n");
    printf("Como nos somos novos,precisamos registrar os novos clientes\n");
    printf("--------------------------//--------------------------\n");
    printf("vamos acessar o nosso menu?\n");
    printf("--------------------------//--------------------------\n");
    printf("para acessar o menu aperte 1, para sair da loja aperte 0:\n");

    scanf("%d", &comeco);

    if (comeco == 1)
    {
        system("cls");
        printf("Ok,vamos ao Menu Principal");
        sleep(1);
        system("cls");
        _clientsize = MenuPrincipal(clienttotalist, _clientsize);
    }
    else if (comeco == 0)
    {
        system("cls");
        printf("\nok,obrigado por nos visitar\n");
        sleep(1);
        system("cls");
        sair();
    }
    else if (comeco < 0 || comeco > 1)
    {
        system("cls");
        printf("opcao invalida, por favor selecione uma opcao valida");
        sleep(1);
        system("cls");
        main();
    }

    int ini2;
aqui:
    printf("--------------------------//--------------------------\n");
    printf("Agora que ja possuimos uma quantidade de clientes cadastrados(as)\n");
    printf("--------------------------//--------------------------\n");
    printf("oque o senhor deseja fazer?\n");
    printf("--------------------------//--------------------------\n");
    printf("para sair, aperte 0:\n");
    printf("--------------------------//--------------------------\n");
    printf("para  acessar a Lista de de escolhas,aperte 1:\n");
    printf("--------------------------//--------------------------\n");

    scanf("%d", &ini2);

    if (ini2 == 0)
    {
        printf("saindo do programa");
        sleep(1);
        system("cls");
        sair();
    }
    else if (ini2 == 1)
    {
        printf("Acessando a lista de escolhas");
        sleep(1);
        system("cls");
        mostrarlista(clienttotalist, _clientsize);
    }
    else if (ini2 != 0 || ini2 != 1)
    {
        printf("opcao invalida,por favor selecione uma opcao valida");
        sleep(1);
        system("cls");
        goto aqui;
    }

    return 0;
}

int MenuPrincipal(Pessoa *_clienttotalist, int _clientsize)
{

    int escolhasmain;

    printf("--------------------------//--------------------------\n");
    printf("BEM VINDO A NOSSA A LOJA!!!!\n");
    printf("--------------------------//--------------------------\n");
    printf("Oque o senhor deseja?\n");
    printf("--------------------------//--------------------------\n");
    printf("Para sair de nossa loja, aperte 0:\n");
    printf("--------------------------//--------------------------\n");
    printf("Para se registrar como cliente, aperte 1:\n");
    printf("--------------------------//--------------------------\n");
    scanf("%d", &escolhasmain);

    system("cls");

    if (escolhasmain == 0)
    {
        printf("\nOBRIGADO POR NOS VISITAR!!!\n");
        sleep(1);
        system("cls");
        sair();
    }
    else if (escolhasmain == 1)
    {
        printf("Redirecionando para o Registro");
        sleep(1);
        system("cls");
        _clientsize = Ccadastros(_clienttotalist);
    }
    else if (escolhasmain < 0 || escolhasmain > 1)
    {
        printf("Escolha invalida,por favor digite um numero valido\n");
        sleep(1);
        system("cls");
        MenuPrincipal(_clienttotalist, _clientsize);
    }
    return _clientsize;
}

Pessoa Ccadastro()
{

    Pessoa cliente;

    printf("--------------------------//--------------------------");
    printf("\nQual seu nome:");
    scanf("%s", &cliente.Pnome);
    printf("\nQual sua data de nascimento:");
    scanf("%d", &cliente.pAnonascimento);
    printf("\nQuanto o senhor(a),gastou no mes passado:");
    scanf("%f", &cliente.Pgastos);

    printf("\nCliente cadastrado\n");
    sleep(1);
    system("cls");

    return cliente;
}

int Ccadastros(Pessoa *_clienttotalist)
{

    int cadscliente;

    Pessoa *arraytotalclient = (Pessoa *)calloc(10, sizeof(Pessoa));

    printf("--------------------------//--------------------------\n");
    printf("Bem vindo ao nosso nosso sistema\n");
    printf("--------------------------//--------------------------\n");
    printf("para sair do programa, aperte 0:\n");
    printf("--------------------------//--------------------------\n");
    printf("Quantos clientes iremos registrar?\n ");

    scanf("%d", &cadscliente);

    sleep(1);
    system("cls");

    if (cadscliente == 0)
    {
        printf("saindo do programa\n");
        sleep(1);
        system("cls");
        sair();
    }
    else if (cadscliente < 0)
    {
        printf("Opcao invalida,por favor digite um numero valido");
        sleep(1);
        system("cls");
        Ccadastros(_clienttotalist);
    }
    else if (cadscliente > 10)
    {
        _clienttotalist = (Pessoa *)realloc(&_clienttotalist, 20 * sizeof(Pessoa));
        arraytotalclient = (Pessoa *)realloc(&arraytotalclient, 20 * sizeof(Pessoa));
    }

    for (int i = 0; i < cadscliente; i++)
    {
        printf("--------------------------//--------------------------\n");
        printf("Cliente %d: \n", i + 1);
        Pessoa _Cliente = Ccadastro();
        arraytotalclient[i] = _Cliente;
    }
    for (int j = 0; j < cadscliente; j++)
    {
        _clienttotalist[j] = arraytotalclient[j];
    }
    return cadscliente;
}

int mostrarlista(Pessoa *_clienttotalist, int _clientsize)
{
    int listchoose;
    printf("\n--------------------------//--------------------------\n");
    printf("Bem vindo a lista de escolhas\n");
    printf("--------------------------//--------------------------\n");
    printf("oque o senhor deseje fazer?\n");
    printf("--------------------------//--------------------------\n");
    printf("Remover cliente e atualizar o montande de gastos do mesmo, aperte 1\n");
    printf("--------------------------//--------------------------\n");
    printf("Zerar todos os montantes de compras por virada de mes, aperte 2\n");
    printf("--------------------------//--------------------------\n");
    printf("listar o melhor comprador,aperte 3\n");
    printf("--------------------------//--------------------------\n");
    printf("exibir um montante de compras por cliente , aperte 4\n");
    printf("--------------------------//--------------------------\n");

    scanf("%d", &listchoose);

    switch (listchoose)
    {
    case 1:
        printf("Remocao de cliente pelo nome\n");
        Ccremover(_clienttotalist, _clientsize);
        printf("\nDepois de 5 segundos o sistema era retornar para A Lista");
        sleep(5);
        system("cls");
        mostrarlista(_clienttotalist, _clientsize);
        break;
    case 2:
        ViradaDomes(_clienttotalist, _clientsize);
        printf("\nDepois de 5 segundos o sistema era retornar para A Lista");
        sleep(5);
        system("cls");
        mostrarlista(_clienttotalist, _clientsize);
        break;
    case 3:
        bestcomprador(_clienttotalist, _clientsize);
        printf("\nDepois de 5 segundos o sistema era retornar para A Lista");
        sleep(5);
        system("cls");
        mostrarlista(_clienttotalist, _clientsize);
        break;
    case 4:
        QuantiaPagaPorCliente(_clienttotalist, _clientsize);
        printf("\nDepois de 5 segundos o sistema era retornar para A Lista");
        sleep(5);
        system("cls");
        mostrarlista(_clienttotalist, _clientsize);
        break;
    }
}

void Ccremover(Pessoa *_clienttotalist, int _clientsize)
{
    bool clienteExist;

    int ini3;

    printf("Voce acabou de entrar Na Remoção de cliente");
    printf("\n--------------------------//--------------------------\n");
    printf("para voltar a lista, Digite 0");
    printf("\n--------------------------//--------------------------\n");
    printf("Para seguir com o programa,Digite 1:\n");
    scanf("%d", &ini3);

    sleep(1);
    system("cls");
    if (ini3 == 0)
    {
        printf("Voltando para a lista...aguarda\n");
        sleep(1);
        system("cls");
        mostrarlista(_clienttotalist, _clientsize);
    }
    else if (ini3 == 1)
    {

        char name[30];
        printf("\n Qual Cliente Que voce deseja remover:");
        scanf("%s", &name);
        int clientback = procurarArrayName(_clienttotalist, _clientsize, name);
        if (clientback == -1)
        {
            printf("Nome invalido,Por favor digite um nome valido");
            sonolimpo();
        }
        else
        {
            bool funcionou = 0;
            funcionou = reallocPos(_clienttotalist, _clientsize, clientback);
            if (funcionou)
            {
                printf("Removendo cliente");
                sonolimpo();
            }
            else
            {
                printf("Nao foi possivel Remover o cliente");
                sonolimpo();
                Ccremover(_clienttotalist, _clientsize);
            }
        }
    }
    else if (ini3 < 0 || ini3 > 1)
    {
        printf("Valor invalido!, por favor digite 1 valor valido");
        sleep(1);
        system("cls");
        Ccremover(_clienttotalist, _clientsize);
    }
}

void Clientlist(Pessoa *_clienttotalist, int _clientsize)
{
    printf("Lista de Clientes\n");
    int i;
    for (i = 0; i <= _clientsize; i++)
    {
        Pessoa *cliente = &_clienttotalist[i];

        printcliente(cliente);
    }
}

int insertionSort(Pessoa *_clienttotalist, int _clientsize)
{
    int i, element, j;
    for (i = 1; i < _clientsize; i++)
    {
        element = _clienttotalist->Pgastos;
        j = i - 1;
        while (j >= 0 && _clienttotalist[j].Pgastos > element)
        {
            _clienttotalist[j + 1].Pgastos = _clienttotalist[j].Pgastos;
            j = j - 1;
        }
        _clienttotalist[j + 1].Pgastos = element;
    }
}

void ViradaDomes(Pessoa *_clienttotalist, int _clientsize)
{
    printf("Virada do mes\n\n");
    int i;
    for (i = 0; i < _clientsize; i++)
    {
        Pessoa *cliente = &_clienttotalist[i];
        _clienttotalist->Pgastos == 0;
    }
    printf("Os Dados foram Zerados, Devido a virada do mes!!!");
    sleep(3);
    system("cls");
}

void bestcomprador(Pessoa *_clienttotalist, int _clientsize)
{

    int c, loc = 0;

    for (c = 0; c < _clientsize; c++)
        for (int c = 1; c < _clientsize; c++)
        {
            Pessoa *cliente = &_clienttotalist[c];

            if ((_clienttotalist[c].Pgastos > _clienttotalist[loc].Pgastos))
            {
                loc = c;
                printf("Melhor Comprador!!");
                printcliente(cliente);
            }
            else
            {
                printf("Nao existe Clientes ou Compradores");
                sonolimpo();
            }
        }
}
void QuantiaPagaPorCliente(Pessoa *_clienttotalist, int _clientsize)
{
    int ini1;
    sonolimpo();
    printf("Voce acabou de entrar No registro de Quantia paga por cliente");
    printf("\n--------------------------//--------------------------\n");
    printf("para voltar a lista, Digite 0");
    printf("\n--------------------------//--------------------------\n");
    printf("Para seguir com o programa,Digite 1:\n");
    scanf("%d", &ini1);
    if (ini1 == 0)
    {
        printf("Retornando a lista de escolhas....Aguarde!");
        sleep(2);
        system("cls");
        mostrarlista(_clienttotalist, _clientsize);
    }
    else if (ini1 == 1)
    {

        char name[30];
        int posClient;

        printf("Digite um nome\n");

        scanf("%s", &name);
        posClient = procurarArrayName(_clienttotalist, _clientsize, name);
        if (posClient == -1)
        {
            printf("Nome Invalido Ou Inexistente, Por Favor digite um nome valido");
            sonolimpo();
        }
        else
        {
            Pessoa *cliente = &_clienttotalist[posClient];
            printcliente(cliente);
            sonolimpo();
            QuantiaPagaPorCliente(_clienttotalist, _clientsize);
        }
    }
    else if (ini1 < 0 || ini1 > 1)
    {
        printf("Valor invalido!, por favor digite 1 valor valido");
        sleep(1);
        system("cls");
        QuantiaPagaPorCliente(_clienttotalist, _clientsize);
    }
}

void printcliente(Pessoa *_clienttotalist)
{
    printf("\nO Cliente %s, gastou %.2f esse mes!\n", _clienttotalist->Pnome, _clienttotalist->Pgastos);
}

bool reallocPos(Pessoa *_clienttotalist, int _clientsize, int pos)
{
    bool funcionou;
    if (pos > _clientsize || pos < 0)
    {
        funcionou = 0;
    }
    else
    {
        funcionou = 1;
        int i;
        for (i = pos; i < _clientsize; i++)
        {
            _clienttotalist[i] = _clienttotalist[i + 1];
        }
        _clientsize--;
    }
    _clienttotalist = (Pessoa *)realloc(_clienttotalist, sizeof(Pessoa) * _clientsize);
    return funcionou;
}

int procurarArrayName(Pessoa *_clienttotalist, int _clientsize, char name[30])
{
    bool nomeExiste = 0;
    int posClienteAchado;
    for (int i = 0; i < _clientsize; i++)
    {
        if (!nomeExiste)
        {
            char nomeAtual[30];
            strcpy(nomeAtual, _clienttotalist[i].Pnome);

            if (strcmp(nomeAtual, name) == 0)
            {
                nomeExiste = 1;
                posClienteAchado = i;
            }
            else
            {
                nomeExiste = 0;
            }
        }
    }
    if (nomeExiste)
    {
        return posClienteAchado;
    }
    else
    {
        posClienteAchado = -1;
        return posClienteAchado;
    }
}

void sair()
{
    _Exit(0);
}

void sonolimpo()
{
    sleep(1);
    system("cls");
}
