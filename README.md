## 💻 Sistema de Vendas da Concessionária DriveTech

[cite_start]Este projeto consiste no desenvolvimento de um sistema de vendas integrado para a **Concessionária DriveTech** [cite: 2][cite_start], que atua na venda de carros e motos em três cidades do Paraná: Londrina, Maringá e Curitiba[cite: 12]. [cite_start]O objetivo é substituir o controle manual, que causa inconsistências e atrasos [cite: 13][cite_start], por um sistema com **interface gráfica amigável** e **estrutura orientada a objetos**[cite: 14].

[cite_start]O sistema deve permitir aos vendedores consultar o estoque, registrar vendas e gerar comprovantes de compra[cite: 14].

### 🛠️ Tecnologias e Conceitos

[cite_start]O desenvolvimento foi realizado utilizando **Programação Orientada a Objetos com C++ e Qt**[cite: 7].

| Conceito/Tecnologia | Aplicação no Projeto |
| :--- | :--- |
| **Padrões de Projeto** | [cite_start]Uso **obrigatório** dos padrões **Singleton** e **Strategy**[cite: 6, 131, 133]. |
| **Singleton** | [cite_start]Gerenciador central de estoque e vendas, responsável por controlar os dados compartilhados entre as filiais[cite: 132, 44]. |
| **Strategy** | [cite_start]Implementação das diferentes **Políticas de Desconto** [cite: 58, 133] [cite_start]de forma flexível e extensível[cite: 61]. |
| **POO** | [cite_start]Uso de classes, pilares da POO, herança e demais relações entre classes[cite: 4, 167]. |
| **Tratamento de Erros** | [cite_start]Utilização de `throw` e `try...catch` [cite: 5] [cite_start]para lidar com erros e exceções (e.g., login inválido, veículo indisponível [cite: 161]). |
| **Interface Gráfica** | [cite_start]Desenvolvimento de Interfaces Gráficas com aplicação dos conceitos de layout, componentes visuais e modelo de eventos[cite: 7, 127, 128]. |

---

### ✨ Funcionalidades Principais

[cite_start]O sistema é acessado por vendedores (usuário/senha pré-definidos [cite: 32][cite_start]) e possui as seguintes telas e funcionalidades[cite: 89]:

* [cite_start]**Tela de Login**: Autenticação de vendedores, com campos para usuário e senha[cite: 90, 91].
* [cite_start]**Tela Principal**: Exibe o nome do vendedor logado [cite: 96] [cite_start]e possui menus para acesso às funcionalidades [cite: 97][cite_start]: Consultar estoque [cite: 98][cite_start], Cadastrar Cliente [cite: 99][cite_start], Registrar venda [cite: 100][cite_start], Listar vendas [cite: 101][cite_start], e Sair[cite: 102].
* [cite_start]**Consulta de Estoque**: Permite consultar carros e motos disponíveis em qualquer filial (Londrina, Maringá, Curitiba) ou em todas[cite: 18]. [cite_start]Exibe o status de disponibilidade[cite: 109].
* **Registro de Venda**:
    * [cite_start]Informação da Filial [cite: 113][cite_start], Tipo e modelo do veículo[cite: 114].
    * [cite_start]Nome e CPF do cliente (que deve estar cadastrado previamente [cite: 115, 54]).
    * [cite_start]Escolha da **Política de Desconto** (Strategy) [cite: 116, 55] [cite_start]e forma de pagamento (à vista/parcelado)[cite: 117, 56].
    * [cite_start]O sistema verifica a disponibilidade [cite: 57][cite_start], calcula o valor total com desconto [cite: 28][cite_start], e define o Status da venda (confirmada ou pendente)[cite: 30].
    * [cite_start]Exibição de resumo da venda[cite: 120, 31].
* [cite_start]**Persistência de Dados**: Geração de um arquivo (`.csv`) contendo todas as vendas realizadas [cite: 67][cite_start], ordenadas por data da mais recente para a mais antiga[cite: 67, 123].

#### 🛒 Políticas de Desconto (Strategy)

[cite_start]O padrão Strategy é utilizado para permitir a aplicação dinâmica das seguintes políticas de desconto[cite: 58, 61]:

| Política | Descrição | Desconto |
| :--- | :--- | :--- |
| Sem desconto | Tarifa padrão | 0% |
| Cliente Fidelidade | Cliente já realizou compra anterior | 5% |
| Promoção Especial | Desconto sazonal ou campanha da marca | 10% |
| Vendas Corporativas | Empresa comprando frota (2 ou + veículos) | 15% |

### 📥 Como Executar

**(Instruções a serem preenchidas após a configuração do ambiente, como compilação do projeto Qt/C++)**

1.  Clone o repositório:
    ```bash
    git clone [https://docs.github.com/pt/repositories/creating-and-managing-repositories/about-repositories](https://docs.github.com/pt/repositories/creating-and-managing-repositories/about-repositories)
    ```
2.  Navegue até o diretório do projeto:
    ```bash
    cd DriveTech-SistemaVendas
    ```
3.  Abra o arquivo `.pro` com o **Qt Creator**.
4.  Configure o *kit* de compilação adequado e compile o projeto.
5.  Execute a aplicação.

### 👥 Dados de Acesso (Testes)

[cite_start]Para fins de teste e demonstração, utilize os seguintes dados de login[cite: 32]:

| Vendedor | Senha |
| :--- | :--- |
| `vendedor1` | [cite_start]`senha1` [cite: 35, 36] |
| `vendedor2` | [cite_start]`senha2` [cite: 37, 38] |
| `vendedor3` | [cite_start]`senha3` [cite: 39, 40] |
| `vendedor4` | [cite_start]`senha4` [cite: 41, 42] |
