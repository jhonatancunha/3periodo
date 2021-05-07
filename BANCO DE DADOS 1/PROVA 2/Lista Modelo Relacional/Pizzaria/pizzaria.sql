DROP DATABASE IF EXISTS pizzaria;
CREATE DATABASE pizzaria;
USE pizzaria;

CREATE TABLE PIZZA (
    numero INTEGER,
    nome VARCHAR(100),
    ingredientes VARCHAR(500),
    PRIMARY KEY (numero)
);

CREATE TABLE TAMANHO (
    descricao VARCHAR(300),
    PRIMARY KEY (descricao)
);

CREATE TABLE PIZZA_TAMANHO (
    numero_pizza INTEGER,
    descricao_tamanho VARCHAR(300),
    PRIMARY KEY (numero_pizza , descricao_tamanho),
    FOREIGN KEY (numero_pizza)
        REFERENCES PIZZA (numero),
    FOREIGN KEY (descricao_tamanho)
        REFERENCES TAMANHO (descricao)
);


CREATE TABLE FUNCIONARIO (
    id INTEGER,
    PRIMARY KEY (id)
);

CREATE TABLE ENTREGADOR (
    id_funcionario INTEGER,
    telefone VARCHAR(11),
    PRIMARY KEY (id_funcionario),
    FOREIGN KEY (id_funcionario)
        REFERENCES FUNCIONARIO (id)
);

CREATE TABLE ATENDENTE (
    id_funcionario INTEGER,
    PRIMARY KEY (id_funcionario),
    FOREIGN KEY (id_funcionario)
        REFERENCES FUNCIONARIO (id)
);

CREATE TABLE BAIRRO (
    nome VARCHAR(100),
    tempo TIME,
    PRIMARY KEY (nome)
);

CREATE TABLE CLIENTE (
    telefone VARCHAR(11),
    nome VARCHAR(100),
    nome_bairro VARCHAR(100),
    PRIMARY KEY (telefone),
    FOREIGN KEY (nome_bairro)
        REFERENCES BAIRRO (nome)
);

CREATE TABLE PEDIDO (
    num INTEGER,
    data_pedido DATETIME,
    telefone_cliente VARCHAR(11),
    endereco VARCHAR(300),
    id_entregador INTEGER,
    id_atendente INTEGER,
    PRIMARY KEY (num),
    FOREIGN KEY (telefone_cliente)
        REFERENCES CLIENTE (telefone),
    FOREIGN KEY (id_entregador)
        REFERENCES ENTREGADOR (id_funcionario),
    FOREIGN KEY (id_atendente)
        REFERENCES ATENDENTE (id_funcionario)
);

CREATE TABLE PEDIDO_PIZZA (
    num_pedido INTEGER,
    numero_pizza INTEGER,
    descricao_tamanho VARCHAR(300),
    PRIMARY KEY (num_pedido , numero_pizza , descricao_tamanho),
    FOREIGN KEY (num_pedido)
        REFERENCES PEDIDO (num),
    FOREIGN KEY (numero_pizza , descricao_tamanho)
        REFERENCES PIZZA_TAMANHO (numero_pizza , descricao_tamanho)
);

