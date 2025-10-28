## 💻 Sistema de Vendas da Concessionária DriveTech

Este projeto consiste no desenvolvimento de um sistema de vendas integrado para a **Concessionária DriveTech**, que atua na venda de carros e motos em três cidades do Paraná: Londrina, Maringá e Curitiba. O objetivo é substituir o controle manual, que causa inconsistências e atrasos, por um sistema com **interface gráfica amigável** e **estrutura orientada a objetos**.

O sistema deve permitir aos vendedores consultar o estoque, registrar vendas e gerar comprovantes de compra.

### 🛠️ Tecnologias e Conceitos

O desenvolvimento foi realizado utilizando **Programação Orientada a Objetos com C++ e Qt**.

| Conceito/Tecnologia | Aplicação no Projeto |
| :--- | :--- |
| **Padrões de Projeto** | Uso **obrigatório** dos padrões **Singleton** e **Strategy**. |
| **Singleton** | Gerenciador central de estoque e vendas, responsável por controlar os dados compartilhados entre as filiais. |
| **Strategy** | Implementação das diferentes **Políticas de Desconto** de forma flexível e extensível. |
| **POO** | Uso de classes, pilares da POO, herança e demais relações entre classes. |
| **Tratamento de Erros** | Utilização de `throw` e `try...catch` para lidar com erros e exceções (e.g., login inválido, veículo indisponível ). |
| **Interface Gráfica** | Desenvolvimento de Interfaces Gráficas com aplicação dos conceitos de layout, componentes visuais e modelo de eventos. |

---

### ✨ Funcionalidades Principais

O sistema é acessado por vendedores (usuário/senha pré-definidos ) e possui as seguintes telas e funcionalidades:

* **Tela de Login**: Autenticação de vendedores, com campos para usuário e senha.
* **Tela Principal**: Exibe o nome do vendedor logado e possui menus para acesso às funcionalidades : Consultar estoque , Cadastrar Cliente , Registrar venda , Listar vendas , e Sair.
* **Consulta de Estoque**: Permite consultar carros e motos disponíveis em qualquer filial (Londrina, Maringá, Curitiba) ou em todas. Exibe o status de disponibilidade.
* **Registro de Venda**:
    * Informação da Filial , Tipo e modelo do veículo.
    * Nome e CPF do cliente (que deve estar cadastrado previamente ).
    * Escolha da **Política de Desconto** (Strategy) e forma de pagamento (à vista/parcelado).
    * O sistema verifica a disponibilidade , calcula o valor total com desconto , e define o Status da venda (confirmada ou pendente).
    * Exibição de resumo da venda.
* **Persistência de Dados**: Geração de um arquivo (`.csv`) contendo todas as vendas realizadas, ordenadas por data da mais recente para a mais antiga.

#### 🛒 Políticas de Desconto (Strategy)

O padrão Strategy é utilizado para permitir a aplicação dinâmica das seguintes políticas de desconto:

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
