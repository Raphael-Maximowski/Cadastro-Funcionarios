
#include <chrono>         // Utilizado para dar Delay nos Outputs
#include <thread>        // Utilizado para dar Delay nos Outputs
#include <iostream> 
#include <cstdlib> //Biblioteca para limpar terminal   
using namespace std;
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif


/*
Código criado para registro de Funcionarios,
visando uma interação contínua com camadas
de "ida e volta" dentro das linhas
@autor Raphael Maximowski, Alan Pereira
*/
int main()
{
    // Variaveis para Login
    string nome_admin;
    int ra_raphael = 2024121372;
    int senha_um;
    int ra_alan = 2024122372;
    int senha_dois;

    cout << boolalpha;

    // Iniciando Código
    cout << "Seja bem vindo ao seu Sistema de Funcionarios" << endl;


    // Iniciando Verificações
    cout << "Para Iniciarmos Insira suas Credenciais!" << endl;
    cout << "Insira seu nome: ";
    getline(cin, nome_admin);  // Getline Utilizado para gravar todo o valor inserido no Input
    cout << "Insira a Primeira senha: ";
    cin >> senha_um;
    cout << "Insira a Segunda senha: ";
    cin >> senha_dois;

    // Laço de Repetição enquanto a senha estiver incorreta
    while (senha_um != ra_raphael || senha_dois != ra_alan) {
        // Verificação 3 tentivas
        int contador_tentivas = 3; // Usuario possui três tentativas para errar o Login
        while (contador_tentivas != 0) {
            contador_tentivas--; // Decremento a cada repetição no Loop
            cout << "\nSenha Invalida, insira novamente!" << endl;
            cout << "Voce possui " << contador_tentivas + 1 << " tentivas! \n";
            cout << "Insira a Primeira senha: ";
            cin >> senha_um;
            cout << "Insira a Segunda senha: ";
            cin >> senha_dois;
            if (senha_um == ra_raphael && senha_dois == ra_alan) {
                break;
            }

            if (contador_tentivas == 0) {
                // Bloqueia o Usuário ao zerar o contador
                cout << "\nUsuario Bloqueado, entre em contato com o suporte para resolver!\n";
                return 0;
            }
        }

    }

    // Inicializando Menu
    cout << "\nSeja bem vindo " << nome_admin << "!" << endl;

    // Definindo parâmetros para permitir a ida e volta no Menu
    int escolha = 0;

    //Vagas para Cadastro
    int vagas_efetivo = 1;
    int vagas_temporario = 1;
    int vagas_estagiario = 1;
    int escolha_funcionario = 0;
    int dias_trabalhados_temporario;
    double num_horas_efetivo;


    // Arrays Funcionarios
    string nome_funcionarios[3];
    string endereco_funcionario[3];
    string cpf_funcionario[3];
    string admissao_funcionario[3];
    string tipo_contrato[3];

    bool voltar_menu_principal = true; // Variável que controlamos o fluxo de entrada e saída, caso seja falso ele 

    // Loop de Repetição até o usuário finalizar o programa
    while (escolha != 3 && voltar_menu_principal) {
        system("cls");
        cout << "\nInsira qual a Operacao Desejada: " << endl;
        cout << "[1] Cadastrar Funcionarios" << endl;
        cout << "[2] Holerites" << endl;
        cout << "[3] Finalizar programa" << endl;
        cout << "Sua escolha: ";
        cin >> escolha;


        // Loop Para Repetir o Código
        while (escolha != 3) {

            //  Opções de [1] Cadastrar Funcionários
            if (escolha == 1) {

                system("cls");

                cout << "\nInsira a Operacao desejada: " << endl;

                cout << "[1] Cadastrar Funcionario Efetivo (" << vagas_efetivo << " vaga (s) disponiveis)" << endl;

                cout << "[2] Cadastrar Funcionario Temporario (" << vagas_temporario << " vaga (s)disponiveis)" << endl;

                cout << "[3] Cadastrar Estagiario (" << vagas_estagiario << " vaga (s) disponiveis)" << endl;

                cout << "[4] Retornar" << endl;
                cout << "Sua escolha: ";
                cin >> escolha_funcionario;

                // Teste caso não exista mais vagas para Efetivo
                if (escolha_funcionario == 1 && vagas_efetivo == 0) {
                    cout << "\nSem vagas Disponiveis!" << endl;
                    cout << "Escolha outra Operacao!" << endl;
                    // Comando para dar Delay no Output
                }

                // Cadastrando Funcionario Efetivo
                if (escolha_funcionario == 1 && vagas_efetivo == 1) {

                    system("cls");

                    vagas_efetivo--; // Decremento para Vagas Disponiveis
                    cout << "\nInicializando Cadastro de Funcionario Efetivo...\n";
                    // Comando para dar Delay no Output

                                       // Preenchendo Dados Funcionario Efetivo
                    cout << "Insira o nome do seu Funcionario: ";
                    cin.ignore();
                    getline(cin, nome_funcionarios[0]); // Getline Utilizado para gravar todo o valor inserido no Input

                    cout << "Insira o endereco do seu Funcionario: ";
                    getline(cin, endereco_funcionario[0]); // Getline Utilizado para gravar todo o valor inserido no Input

                    cout << "Insira o CPF do seu Funcionario: ";
                    cin >> cpf_funcionario[0];

                    cout << "Data de admissao: ";
                    cin.ignore();
                    getline(cin, admissao_funcionario[0]); // Getline Utilizado para gravar todo o valor inserido no Input

                    cout << "Numero de horas extras: ";
                    cin >> num_horas_efetivo;


                    tipo_contrato[0] = "Efetivo"; // Guarda o tipo de funcionario para o momento de calculo

                    cout << "Usuario Cadastrado com Sucesso\n";
                    // Comando para dar Delay no Output
                    cout << "\nRealize sua Proxima Operacao!";

                }

                // Teste caso não exista mais vagas para Temporario
                if (escolha_funcionario == 2 && vagas_temporario == 0) {
                    cout << "\nSem vagas Disponiveis!" << endl;
                    cout << "Escolha outra Operacao!" << endl;
                    // Comando para dar Delay no Output
                }
                // Cadastrando Funcionario Temporario
                if (escolha_funcionario == 2 && vagas_temporario == 1) {
                    vagas_temporario--; // Decremento para Vagas Disponiveis

                    system("cls");

                    cout << "\nInicializando Cadastro de Funcionario Temporario...\n";


                    // Preenchendo Dados Funcionario Temporario
                    cout << "Insira o nome do seu Funcionario: ";
                    cin.ignore();
                    getline(cin, nome_funcionarios[1]); // Getline Utilizado para gravar todo o valor inserido no Input

                    cout << "Insira o endereco do seu Funcionario: ";
                    getline(cin, endereco_funcionario[1]); // Getline Utilizado para gravar todo o valor inserido no Input

                    cout << "Insira o CPF do seu Funcionario: ";
                    cin >> cpf_funcionario[1];

                    cout << "Data de admissao: ";
                    cin.ignore();
                    getline(cin, admissao_funcionario[1]); // Getline Utilizado para gravar todo o valor inserido no Input

                    cout << "Numero de dias trabalhados no mes: ";
                    cin >> dias_trabalhados_temporario;

                    tipo_contrato[1] = "Temporario"; // Guarda o tipo de funcionario para o momento de calculo

                    cout << "Usuario Cadastrado com Sucesso\n";
                    // Comando para dar Delay no Output
                    cout << "\nRealize sua Proxima Operacao!" << endl;

                }

                // Teste caso não exista mais vagas para Estagiario
                if (escolha_funcionario == 3 && vagas_estagiario == 0) {
                    cout << "\nSem vagas Disponiveis!" << endl;
                    cout << "Escolha outra Operacao!" << endl;
                    // Comando para dar Delay no Output
                }
                // Cadastrando Estagiario
                if (escolha_funcionario == 3 && vagas_estagiario == 1) {

                    system("cls");

                    vagas_estagiario--; // Decremento para Vagas Disponiveis
                    cout << "\nInicializando Cadastro de Estagiario...\n";
                    // Comando para dar Delay no Output

                                        // Preenchendo Dados de Estagiarios
                    cout << "Insira o nome do seu Funcionario: ";
                    cin.ignore();
                    getline(cin, nome_funcionarios[2]); // Getline Utilizado para gravar todo o valor inserido no Input

                    cout << "Insira o endereco do seu Funcionario: ";
                    getline(cin, endereco_funcionario[2]); // Getline Utilizado para gravar todo o valor inserido no Input

                    cout << "Insira o CPF do seu Funcionario: ";
                    cin >> cpf_funcionario[2];

                    cout << "Data de admissao: ";
                    cin.ignore();
                    getline(cin, admissao_funcionario[2]); // Getline Utilizado para gravar todo o valor inserido no Input

                    tipo_contrato[2] = "Estagiario"; // Guarda o tipo de funcionario para o momento de calculo

                    cout << "Usuario Cadastrado com Sucesso\n";
                    cout << "\nRealize sua Proxima Operacao!";
                }

                // Retornando para o Menu Anterior
                if (escolha_funcionario == 4) {
                    cout << "\nRetornando a pagina anterior!\n";
                    break;
                }

                // Operação Maior que 4 Invalida
                if (escolha_funcionario > 4) {
                    cout << "\nOperacao Invalida, Insira novamente!";

                    break;
                }


                // Verifica se a escolha for igual a 2 e voltar para menu principal seja igual a true
            }
            else if (escolha == 2 || !voltar_menu_principal) {
                // Após isso entramos na estrutura do else if

                // Variáveis para controlar a entrada e saída 
                int escolha_holerite;
                bool voltar_menu_holerite = false;

                // Enquanto entrar ao menu de holerite for falso repete o loop 
                while (!voltar_menu_holerite) {

                    system("cls"); // Limpa o terminal de saída

                    cout << "MENU HOLERITE: " << endl;

                    // Essa estrutura for fiz para exibir os usuários cadastrados, onde só será exibido se nome usuário não estiver vazio naquela posição dentro do array
                    for (int i = 0; i < 3; i++) {
                        // Caso não esteja vazio
                        if (nome_funcionarios[i] != "") {
                            cout << "[" << i + 1 << "]" << nome_funcionarios[i] << endl;
                        }
                        else if (nome_funcionarios[i] == "" && nome_funcionarios[i + 1] == "" && nome_funcionarios[i + 2] == "") {
                            cout << "NENHUM USUARIO CADASTRADO!" << endl;
                        }
                        // Caso esteja vazio

                    }

                    cout << "[4]Retornar" << endl;
                    // Aqui o usuário digita a opção desejada
                    cout << "DIGITE OPCAO DESEJADA: ";
                    cin >> escolha_holerite;

                    // Se sua escolha for igual a um será direcionado para o a opção de funcionário igual a 1
                    if (escolha_holerite == 1) {

                        system("cls");

                        double salario_bruto_efetivo = 1420.00;
                        double desconto_percentual_efetivo = 20.0; // percentual de desconto
                        double descontos_efetivo = salario_bruto_efetivo * (desconto_percentual_efetivo / 100.0);
                        double salario_liquido_efetivo = salario_bruto_efetivo - descontos_efetivo;
                        double valor_horas_extras_efetivo = (((salario_liquido_efetivo / 30.0) / 8.0) * num_horas_efetivo);

                        cout << "------------- HOLERITE ---------------" << endl;
                        cout << "\nNOME: " << nome_funcionarios[0] << endl;
                        cout << "ENDERECO: " << endereco_funcionario[0] << endl;
                        cout << "CPF: " << cpf_funcionario[0] << endl;
                        cout << "DATA DE ADMISSAO: " << admissao_funcionario[0] << endl;
                        cout << "TIPO DE CONTRATO: " << tipo_contrato[0] << endl;
                        cout << "SALARIO BRUTO: " << salario_bruto_efetivo << endl;
                        cout << "VALOR DESCONTOS: " << descontos_efetivo << endl;
                        cout << "SALARIO LIQUIDO: " << salario_liquido_efetivo << endl;
                        cout << "VALOR HORAS EXTRAS: " << valor_horas_extras_efetivo << endl;
                        cout << "SALARIO TOTAL: " << salario_liquido_efetivo + valor_horas_extras_efetivo << endl;


                        cout << "\n\nSe quer sair digite (0)." << endl;
                        cin >> voltar_menu_holerite;

                    }
                    else if (escolha_holerite == 2) { // Caso opção seja igual a 2

                        system("cls");

                        double salario_base_temporario = 1420.00;
                        double desconto_porcentual_temporario = 20.00;
                        double salario_bruto_temporario = ((salario_base_temporario / 30) * dias_trabalhados_temporario);
                        double descontos_temporario = (salario_bruto_temporario * (desconto_porcentual_temporario / 100));
                        double salario_liquido_temporario = salario_bruto_temporario - descontos_temporario;

                        cout << "------------- HOLERITE ---------------" << endl;
                        cout << "\nNOME: " << nome_funcionarios[1] << endl;
                        cout << "ENDERECO: " << endereco_funcionario[1] << endl;
                        cout << "CPF: " << cpf_funcionario[1] << endl;
                        cout << "DATA DE ADMISSAO: " << admissao_funcionario[1] << endl;
                        cout << "TIPO DE CONTRATO: " << tipo_contrato[1] << endl;
                        cout << "SALARIO BRUTO: " << salario_bruto_temporario << endl;
                        cout << "VALOR DESCONTOS: " << "R$ " << descontos_temporario << endl;
                        cout << "VALOR SALARIO LIQUIDO: " << "R$ " << salario_liquido_temporario << endl;
                        cout << "VALOR HORAS EXTRAS TRABALHADAS: " << "R$ " << 00.00 << endl;
                        cout << "SALARIO TOTAL: " << "R$ " << salario_liquido_temporario << endl;

                        cout << "\n\nSe quer sair digite (0)." << endl; // Caso digite (0) á variável será falsa e saíra do if e else e retornará ao loop
                        cin >> voltar_menu_holerite;

                    }
                    else if (escolha_holerite == 3) {

                        system("cls");

                        double salario_bruto_estagiario = 800.00;

                        cout << "------------- HOLERITE ---------------" << endl;
                        cout << "\nNOME: " << nome_funcionarios[2] << endl;
                        cout << "ENDERECO: " << endereco_funcionario[2] << endl;
                        cout << "CPF: " << cpf_funcionario[2] << endl;
                        cout << "DATA DE ADMISSAO: " << admissao_funcionario[2] << endl;
                        cout << "TIPO DE CONTRATO: " << tipo_contrato[2] << endl;
                        cout << "SALARIO BRUTO: " << "R$ " << salario_bruto_estagiario << endl;
                        cout << "VALOR DESCONTOS: " << "R$ " << 00.00 << endl;
                        cout << "SALARIO LIQUIDO: " << "R$ " << salario_bruto_estagiario << endl;
                        cout << "VALOR HORAS EXTRAS TRABALHADAS: " << "R$ " << 00.00 << endl;
                        cout << "SALARIO TOTAL: " << "R$ " << salario_bruto_estagiario << endl;

                        cout << "\n\nSe quer sair digite (0)." << endl;
                        cin >> voltar_menu_holerite;
                    }
                    else if (escolha_holerite == 4) {
                        voltar_menu_holerite = true;
                        cout << voltar_menu_holerite << endl;
                    }
                    else
                        system("cls");

                    cout << "OPCAO INDISPONIVEL" << endl;

                }
                // Aqui saimos da estrutura do if e else
                // O break é usado para sair do if e else que entramos no menu inicial
                break;

            }
        }


    }



    // Finalização Programa
    cout << "\nFinalizando Programa, Ate a proxima :)";

    return 0;
}