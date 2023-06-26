#include<iostream>
#include<conio.h>
#include<locale.h>

using namespace std;

struct TipoProd{
	int cod;
	string desc;
};

struct Produto{
	int cod;
	string desc;
	int codTipo;
	int codFornecedor;
	int qtdeEstoque;
	int qtdeMin;
	int qtdeMax;
	float valor;
};

struct Estado{
	int cod;
	string nome;
};

struct Fornecedor{
	int cod;
	string nome;
	string endereco;
	int tel;
	string cidade;
	int codUf;
	int cnpj;
};

//Buscas

int buscarProduto(Produto p[], int b, int t){
	int i = 0, f = t-1;
    int m = (i + f) / 2;
    for (; f >= i and b != p[m].cod; m = (i + f) / 2){
        if (b > p[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (b != p[m].cod){
        m = -1;
    }
    return(m);
}

int buscarTipo(TipoProd tipo[], int b, int t){
	int i = 0, f = t-1;
    int m = (i + f) / 2;
    for (; f >= i and b != tipo[m].cod; m = (i + f) / 2){
        if (b > tipo[m].cod){
            i = m + 1;
        }
        else{
            f = m - 1;
        }
    }
    if (b != tipo[m].cod){
        m = -1;
    }
    return(m);
}

int buscarFornecedor(Fornecedor fornec[], int b, int t){
	int i = 0, f = t-1;
    int m = (i + f) / 2;
    for (; f >= i and b != fornec[m].cod; m = (i + f) / 2){
        if (b > fornec[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (b != fornec[m].cod){
        m = -1;
    }
	return(m);
}

bool confirmarEstado(Estado e[], int b, int t){
	int i = 0, f = t-1;
    int m = (i + f) / 2;
    bool achou = false;
    for (; f >= i and b != e[m].cod; m = (i + f) / 2){
        if (b > e[m].cod){
            i = m + 1;
        }
        else{
            f = m - 1;
        }
    }
    if (b == e[m].cod){
        cout<<"---------------------------------------"<<endl;
		cout<<"Codigo do Estado: "<<e[m].cod<<endl;
		cout<<"Nome do Estado: "<<e[m].nome<<endl;
		cout<<"---------------------------------------"<<endl;
		achou = true;
    }
    return(achou);
}

// 1 LEITURAS
void lerTipoProd( TipoProd v[], int t){
	for(int i=0; i<t; i++){
		cout<<"-----LEITURA--TIPO--PRODUTO-----"<<endl;
		cout<<"("<<i+1<<")"<<endl;
		cout<<"Digite o Codigo: ";
		cin>>v[i].cod;
		cout<<"Digite a Descrição do Tipo do Produto: ";
		cin>>v[i].desc;
		system("cls");
	}
	cout<<"Leitura do Tipo do Produto Finalizada"<<endl;
	system("PAUSE");
}

void lerProduto( Produto p[], TipoProd tipo[], Fornecedor f[], int t, int t2){ // T2 -> Permiter ler Todos os Fornecedores cadastrados
	for(int i=0; i<t; i++){
		cout<<"-----LEITURA--PRODUTO-----"<<endl;
		cout<<"("<<i+1<<")"<<endl;
		cout<<"Digite o Codigo: ";
		cin>>p[i].cod;
		cout<<"Digite a Descrição do Produto: ";
		cin>>p[i].desc;
		for(int j=0; j<t; j++){
			cout<<"\t-----LISTA--TIPO-PRODUTO-----"<<endl;
			cout<<"\tCodigo: "<<tipo[j].cod<<endl;
			cout<<"\tDescrição: "<<tipo[j].desc<<endl;
		}
		cout<<"-----------------------------"<<endl;
		cout<<"Digite o Codigo do Tipo de Produto Desejado: ";
		cin>>p[i].codTipo;
		for(int j=0; j<t2; j++){
			cout<<"\t-----LISTA--FORNECEDOR-----"<<endl;
			cout<<"\tCodigo: "<<f[j].cod<<endl;
			cout<<"\tNome: "<<f[j].nome<<endl;
		}
		cout<<"---------------------------"<<endl;
		cout<<"Digite o Codigo do Fornecedor Desejado: ";
		cin>>p[i].codFornecedor;
		cout<<"Digite a Quantidade de Estoque: ";
		cin>>p[i].qtdeEstoque;
		cout<<"Digite a Quantidade Mínima do Estoque: ";
		cin>>p[i].qtdeMin;
		cout<<"Digite a Quantidade Máxima do Estoque: ";
		cin>>p[i].qtdeMax;
		cout<<"Digite o Valor Unitário: ";
		cin>>p[i].valor;
		system("cls");
	}
	cout<<"Leitura do Produto Finalizada"<<endl;
	system("PAUSE");
}

void lerEstado(Estado v[], int t){
	for(int i=0; i<t; i++){
		cout<<"-----LEITURA--ESTADO-----"<<endl;
		cout<<"("<<i+1<<")"<<endl;
		cout<<"Digite o Codigo: ";
		cin>>v[i].cod;
		cout<<"Digite o Nome: ";
		cin>>v[i].nome;
		system("cls");
	}
	cout<<"Leitura do Estado Finalizada"<<endl;
	system("PAUSE");
}

void lerFornecedor(Fornecedor f[], Estado e[], int t){
	for(int i=0; i<t; i++){
		cout<<"-----LEITURA--FORNECEDOR-----"<<endl;
		cout<<"("<<i+1<<")"<<endl;
		cout<<"Digite o Codigo: ";
		cin>>f[i].cod;
		cout<<"Digite o Nome: ";
		cin>>f[i].nome;
		cout<<"Digite o Endereço: ";
		cin>>f[i].endereco;
		cout<<"Digite o Telefone: ";
		cin>>f[i].tel;
		cout<<"Digite a Cidade: ";
		cin>>f[i].cidade;
		for(int j=0; j<t; j++){
			cout<<"\t-----LISTA--ESTADO-----"<<endl;
			cout<<"\tCodigo: "<<e[j].cod<<endl;
			cout<<"\tNome: "<<e[j].nome<<endl;
		}
		cout<<"-----------------------"<<endl;
		cout<<"Digite o Codigo do Estado Desejado: ";
		cin>>f[i].codUf;
		cout<<"Digite o CNPJ: ";
		cin>>f[i].cnpj;
		system("cls");
	}
	cout<<"Leitura do Fornecedor Finalizada"<<endl;
	system("PAUSE");
}
// 2 INCLUIR FORNECEDOR
void incluirFornecedor(Fornecedor original[], Fornecedor final[], Estado e[], int t){
	Fornecedor f[t];
	for(int i=0; i<t; i++){
		cout<<"-----INSERIR--FORNECEDOR-----"<<endl;
		bool busca;
		cout<<"("<<i+1<<")"<<endl;
		cout<<"Digite o Codigo: ";
		cin>>f[i].cod;
		cout<<"Digite o Nome: ";
		cin>>f[i].nome;
		cout<<"Digite o Endereço: ";
		cin>>f[i].endereco;
		cout<<"Digite o Telefone: ";
		cin>>f[i].tel;
		cout<<"Digite a Cidade: ";
		cin>>f[i].cidade;
		cout<<"Digite o Codigo do Estado Desejado: ";
		cin>>f[i].codUf;
		busca = confirmarEstado(e, f[i].codUf, t);
		while(busca == false){
			cout<<"-----ESTADO--INCORRETO-----"<<endl;
			cout<<"Digite o Codigo do Estado Desejado: ";
			cin>>f[i].codUf;
			busca = confirmarEstado(e, f[i].codUf, t);
		}
		cout<<"Digite o CNPJ: ";
		cin>>f[i].cnpj;
		system("cls");
	}
	
	// Realizando a Inclusão dos Documentos
	int i=0, j=0, z=0;
	for(;i<t and j<t; z++){
		if(original[i].cod < f[j].cod){
			final[z] = original[i];
			i++;
		}
		else{
			final[z] = f[j];
			j++;
		}
	}

	for(; i<t; i++){
		final[z] = original[i];
		z++;
	}

	for(; j<t; j++){
		final[z] = f[j];
		z++;
	}
	
	cout<<"Fornecedores Inseridos com Sucesso"<<endl;
	system("PAUSE");
}
// 3 INCLUIR PRODUTOS
void incluirProdutos(Produto original[], Produto final[], Fornecedor f[], int t, int t2){
	Produto p[t];
	for(int i=0; i<t; i++){
		cout<<"-----INSERIR--PRODUTO-----"<<endl;
		int id = -1;
		int busca;
		cout<<"("<<i+1<<")"<<endl;
		cout<<"Digite o Codigo: ";
		cin>>p[i].cod;
		busca = buscarProduto(original, p[i].cod, t);
		while(busca != -1 or p[i].cod >= id){ // Verificação da Ordem e do Codigo do PRoduto
			cout<<"-----PRODUTO--JÁ--CADASTRADO--OU--FORA--DE--ORDEM-----"<<endl;
			cout<<"Digite o Codigo de um Produto: ";
			cin>>p[i].cod;
			busca = buscarProduto(original, p[i].cod, t);
		}
		id = p[i].cod;
		cout<<"Digite a Descrição do Produto: ";
		cin>>p[i].desc;
		cout<<"Digite o Codigo do Tipo de Produto Desejado: ";
		cin>>p[i].codTipo;
		cout<<"Digite o Codigo do Fornecedor Desejado: ";
		cin>>p[i].codFornecedor;
		busca = buscarFornecedor(f, p[i].codFornecedor, t2);
		while( busca == -1){
			cout<<"-----FORNECEDOR--INCORRETO-----"<<endl;
			cout<<"Digite o Codigo do Fornecedor Desejado: ";
			cin>>p[i].codFornecedor;
			busca = buscarFornecedor(f, p[i].codFornecedor, t2);
		}
		cout<<"---------------------------------------"<<endl;
		cout<<"Codigo do Fornecedor: "<<f[busca].cod<<endl;
		cout<<"Nome do Fornecedor: "<<f[busca].nome<<endl;
		cout<<"---------------------------------------"<<endl;
		cout<<"Digite a Quantidade de Estoque: ";
		cin>>p[i].qtdeEstoque;
		cout<<"Digite a Quantidade Mínima do Estoque: ";
		cin>>p[i].qtdeMin;
		cout<<"Digite a Quantidade Máxima do Estoque: ";
		cin>>p[i].qtdeMax;
		cout<<"Digite o Valor Unitário: ";
		cin>>p[i].valor;
		system("cls");
	}

	int i=0, j=0, z=0;
	for(;i<t and j<t; z++){
		if(original[i].cod < p[j].cod){
			final[z] = original[i];
			i++;
		}
		else{
			final[z] = p[j];
			j++;
		}
	}
	
	for(; i<t; i++){
		final[z] = original[i];
		z++;
	}
	
	for(; j<t; j++){
		final[z] = p[j];
	}
	
	cout<<"Produtos Inseridos com Sucesso"<<endl;
	system("PAUSE");
}
// 4 REALIZAR VENDAS
void addVenda(Produto p[], Fornecedor f[], TipoProd tipo[], int t, int t2){
	int aux, id;
	char r;
	cout<<"-----ADICIONAR--VENDA-----"<<endl;
	cout<<"Digite o Codigo do Produto que Deseja Realizar a Venda: ";
	cin>>id;
	
	id = buscarProduto(p, id, t);
	id = aux;
	cout<<"Descrição do Produto: "<<p[id].desc<<endl;
	cout<<"Quantidade de Estoque: "<<p[id].qtdeEstoque<<endl;
	cout<<"Valor Unitário: "<<p[id].valor<<endl;
	
	aux = buscarTipo(tipo, p[id].codTipo, t2);
	cout<<"Codigo do Tipo: "<<tipo[aux].cod<<endl;
	cout<<"Descrição do Tipo: "<<tipo[aux].desc<<endl;
	
	aux = buscarFornecedor(f, p[id].codFornecedor, t);
	cout<<"Codigo do Fornecedor: "<<f[aux].cod<<endl;
	cout<<"Nome do Fornecedor: "<<f[aux].nome<<endl;
	
	cout<<"--------------------------"<<endl;
	cout<<"Digite a Quantidade a ser Vendida deste Produto: ";
	cin>>aux;
	while(aux > p[id].qtdeEstoque){
		cout<<"-----PEDIDO--ACIMA--DO--LIMITE-----"<<endl;
		cout<<"\tLimite: "<<p[id].qtdeEstoque<<endl;
		cout<<"Digite a Quantidade a ser Vendida deste Produto: ";
		cin>>aux;
	}
	cout<<"Total do Pedido: R$ "<<aux*p[id].valor<<endl;
	cout<<"Deseja Confirmar a Compra(S/N): ";
	cin>>r;
	r=toupper(r);
	if(r == 'S'){
		cout<<"Venda Confirmada"<<endl;
		p[id].qtdeEstoque -= aux;
	}
	else{
		cout<<"Venda Cancelada"<<endl;
	}
	system("PAUSE");
}
// 5 CONSULTAR DADOS DO PRODUTO
void consultarDados(Produto p[], Fornecedor f[], TipoProd tipo[], int t, int t2){
	int aux, id;
	string r;
	cout<<"-----CONSULTAR--DADOS--PRODUTOS-----"<<endl;
	cout<<"Digite o Codigo do Produto que Deseja Visualizar: ";
	cin>>id;
	
	aux = buscarProduto(p, id, t);
	id = aux;
	if(p[id].qtdeEstoque > 0){
		cout<<"Codigo do Produto: "<<p[id].cod<<endl;
		cout<<"Descrição do Produto: "<<p[id].desc<<endl;
	
		aux = buscarTipo(tipo, p[id].codTipo, t2);
		cout<<"Descrição do Tipo: "<<tipo[aux].desc<<endl;
	
		aux = buscarFornecedor(f, p[id].codFornecedor, t);
		cout<<"Nome do Fornecedor: "<<f[aux].nome<<endl;
		
		cout<<"Quantidade de Estoque: "<<p[id].qtdeEstoque<<endl;
		cout<<"Quantidade Mínima de Estoque: "<<p[id].qtdeMin<<endl;
		cout<<"Quantidade Máxima de Estoque: "<<p[id].qtdeMax<<endl;
		cout<<"Valor Unitário: "<<p[id].valor<<endl;
		
		cout<<"Valor Total em Estoque: "<<p[id].qtdeEstoque * p[id].valor<<endl;
	}
	else{
		cout<<"Produto abaixo do estoque"<<endl;
	}
	system("PAUSE");
}
// 6 CONSULTAR DADOS ABAIXO DO MINIMO
void exibirDadosAbaixo(Produto p[], Fornecedor f[], int t){
	float total=0;
	cout<<"-----PRODUTOS--ABAIXO--DO--ESTOQUE-----"<<endl;
	for(int i=0; i<t; i++){
		if(p[i].qtdeEstoque < p[i].qtdeMin){
			int aux;
			cout<<"---------------------------------------"<<endl;
			cout<<"Codigo do Produto: "<<p[i].cod<<endl;
			cout<<"Descrição do Produto: "<<p[i].desc<<endl;
			cout<<"Quantidade de Estoque: "<<p[i].qtdeEstoque<<endl;
			cout<<"Quantidade Máxima de Estoque: "<<p[i].qtdeMax<<endl;
			
			cout<<"Quantidade a ser Comprada: "<< p[i].qtdeMax - p[i].qtdeEstoque<<endl;
			total += (p[i].qtdeMax - p[i].qtdeEstoque) * p[i].valor;
			cout<<"Valor da Compra: "<< (p[i].qtdeMax - p[i].qtdeEstoque) * p[i].valor<<endl;
			
			aux = buscarFornecedor(f, p[i].codFornecedor, t);
			cout<<"Nome do Fornecedor: "<<f[aux].nome<<endl;
			cout<<"Telefone do Fornecedor: "<<f[aux].tel<<endl;
		}
	}
	if(total != 0 ){
		cout<<"---------------------------------------"<<endl;
		cout<<"Total a ser Comprado: "<<total<<endl;
	}
	else{
		cout<<"---------------------------------------"<<endl;
		cout<<"Nenhum Produto Abaixo do Estoque"<<endl;
	}
	system("PAUSE");
}

//MAIN//
int main(){
	setlocale(LC_ALL,"");
	
	int sair = 0;
	int t = 5;
	int op;
	
	TipoProd tipo[t];
	Produto produto[t];
	Estado uf[t];
	Fornecedor fornecedor[t];
	
	Produto NovoProduto[t*2];
	Fornecedor NovoFornecedor[t*2];
	
	bool leitura[4] = {false, false, false, false};
	bool inclusao[2] = {false, false};
	
	while(sair==0){
		system("cls");
		cout<<"Opções:"<<endl;
		cout<<"\t1-Ler Tipo Produto"<<endl;
		cout<<"\t2-Ler Estado"<<endl;
		cout<<"\t3-Ler Fornecedor"<<endl;
		cout<<"\t4-Ler Produto"<<endl;
		cout<<"\t5-Incluir Novos Fornecedores"<<endl;
		cout<<"\t6-Incluir Novos Produtos"<<endl;
		cout<<"\t7-Realizar Vendas do Produto"<<endl;
		cout<<"\t8-Consultar Produto"<<endl;
		cout<<"\t9-Consultar Produtos Abaixo do Estoque"<<endl;
		cout<<"\t10-Sair"<<endl;
		cout<<"Digite o número da opção que deseja realizar: ";
		cin>>op;
		switch(op){
			case 1:{
				system("cls");
				if(leitura[0] != true){
					lerTipoProd(tipo, t);
					leitura[0] = true;
				}
				else{
					cout<<"Leituras já Feitas"<<endl;
					system("PAUSE");
				}
				break;
			}
			case 2:{
				system("cls");
				if(leitura[1] != true){
					lerEstado(uf, t);
					leitura[1] = true;
				}
				else{
					cout<<"Leituras já Feitas"<<endl;
					system("PAUSE");
				}
				break;
			}
			case 3:{
				system("cls");
				if(leitura[2] != true and leitura[1]){
					lerFornecedor(fornecedor, uf, t);
					leitura[2] = true;
				}
				else{
					if(leitura[1] != true){
						cout<<"Realize as Leituras Primeiro"<<endl;
					}
					else{
						cout<<"Leituras já Feitas"<<endl;
					}
					system("PAUSE");
				}
				break;
			}
			case 4:{
				system("cls");
				if(leitura[3] != true and leitura[0] and leitura[2]){
					if(inclusao[0]){
						lerProduto(produto, tipo, NovoFornecedor, t, t*2);
					}
					else{
						lerProduto(produto, tipo, fornecedor, t, t);
					}
					leitura[3] = true;
				}
				else{
					if(leitura[3]){
						cout<<"Leituras já Feitas"<<endl;
					}
					else{
						cout<<"Realize as Leituras Primeiro"<<endl;
					}
					system("PAUSE");
				}
				break;
			}
			case 5:{
				system("cls");
				if(leitura[2] and inclusao[0] != true ){
					incluirFornecedor(fornecedor, NovoFornecedor, uf, t);
					inclusao[0] = true;
				}
				else{
					if(inclusao[0]){
						cout<<"Leituras já Feitas"<<endl;
					}
					else{
						cout<<"Realize as Leituras Primeiro"<<endl;
					}
					system("PAUSE");
				}
				break;
			}
			case 6:{
				system("cls");
				if(leitura[3] and inclusao[1] != true ){
					if(inclusao[0]){
						incluirProdutos(produto, NovoProduto, NovoFornecedor, t, t*2);
					}
					else{
						incluirProdutos(produto, NovoProduto, fornecedor, t, t);
					}
					inclusao[1] = true;
				}
				else{
					if(inclusao[1]){
						cout<<"Leituras já Feitas"<<endl;
					}
					else{
						cout<<"Realize as Leituras Primeiro"<<endl;
					}
					system("PAUSE");
				}
				break;
			}
			case 7:{
				system("cls");
				if(inclusao[0] and inclusao[1]){
					addVenda(NovoProduto, NovoFornecedor, tipo, t*2, t);
				}
				else{
					if(leitura[3]){
						addVenda(produto, fornecedor, tipo, t, t);
					}
					else{
						cout<<"Realize as Leituras Primeiro"<<endl;
						system("PAUSE");
					}
				}
				break;
			}
			case 8:{
				system("cls");
				if(inclusao[0] and inclusao[1]){
					consultarDados(NovoProduto, NovoFornecedor, tipo, t*2, t);
				}
				else{
					if(leitura[3]){
						consultarDados(produto, fornecedor, tipo, t, t);
					}
					else{
						cout<<"Realize as Leituras Primeiro"<<endl;
						system("PAUSE");
					}
				}
				break;
			}
			case 9:{
				system("cls");
				if(inclusao[0] and inclusao[1]){
					exibirDadosAbaixo(NovoProduto, NovoFornecedor, t*2);
				}
				else{
					if(leitura[3]){
						exibirDadosAbaixo(produto, fornecedor, t);
					}
					else{
						cout<<"Realize as Leituras Primeiro"<<endl;
						system("PAUSE");
					}
				}
				break;
			}
			case 10:{
				sair=1;
				break;
			}
			default:{
				system("cls");
				cout<<"Opção Não Encontrada"<<endl;
				system("PAUSE");
				break;
			}
		}
}
	cout<<"Fim do Programa"<<endl;
	system("PAUSE");
}
