DROP DATABASE IF EXISTS oficina;
CREATE DATABASE oficina;
USE oficina;

CREATE TABLE CATEGORIA (
	nome VARCHAR(100),
    custo FLOAT(10, 2),
    PRIMARY KEY(nome)
);

CREATE TABLE FUNCIONARIO (
	id INTEGER,
    nome VARCHAR(200),
    telefone VARCHAR(11),
    endereco VARCHAR(300),
    nome_categoria VARCHAR(100),
    PRIMARY KEY (id),
    FOREIGN KEY (nome_categoria) REFERENCES CATEGORIA(nome)
);

CREATE TABLE VEICULO(
	placa CHAR(7),
    PRIMARY KEY (placa)
);

CREATE TABLE CLIENTE(
	id INTEGER,
    nome VARCHAR(200),
    telefone VARCHAR(11),
    endereco VARCHAR(300),
    PRIMARY KEY (id)
);

CREATE TABLE CLIENTE_VEICULO(
	id_cliente INTEGER,
    placa_veiculo CHAR(7),
    PRIMARY KEY(id_cliente, placa_veiculo),
    FOREIGN KEY (placa_veiculo) REFERENCES VEICULO(placa),
    FOREIGN KEY (id_cliente) REFERENCES CLIENTE(id)
);

CREATE TABLE REPARO (
	id INTEGER,
    custo FLOAT(10, 2),
    data_reparo DATE,
    id_cliente INTEGER,
    placa_veiculo CHAR(7),
    PRIMARY KEY (id),
    FOREIGN KEY (id_cliente, placa_veiculo) 
		REFERENCES CLIENTE_VEICULO(id_cliente, placa_veiculo)
);

CREATE TABLE PECA(
	cod INTEGER,
    descricao VARCHAR(300),
    custo FLOAT(10, 2),
    qtd INTEGER,
    PRIMARY KEY (cod)
);

CREATE TABLE REPARO_PECA(
	cod_peca INTEGER,
    id_reparo INTEGER,
    custo FLOAT(10, 2),
    PRIMARY KEY(cod_peca, id_reparo),
    FOREIGN KEY (cod_peca) REFERENCES PECA(cod),
    FOREIGN KEY (id_reparo) REFERENCES REPARO(id)
);

CREATE TABLE MAO_DE_OBRA(
	id_reparo INTEGER,
    id_funcionario INTEGER,
    tempo TIME,
    custo FLOAT(10, 2),
    PRIMARY KEY(id_reparo, id_funcionario),
    FOREIGN KEY (id_reparo) REFERENCES REPARO(id),
    FOREIGN KEY (id_funcionario) REFERENCES FUNCIONARIO(id)
);