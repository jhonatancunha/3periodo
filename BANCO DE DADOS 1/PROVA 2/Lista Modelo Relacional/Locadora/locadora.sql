DROP DATABASE IF EXISTS locadora;
CREATE DATABASE locadora;
USE locadora;


CREATE TABLE GENERO (
	descricao VARCHAR(200),
    PRIMARY KEY (descricao)
);

CREATE TABLE FILME (
	id INTEGER,
    nome VARCHAR(100),
    genero_descricao VARCHAR (200),
    PRIMARY KEY (id),
    FOREIGN KEY (genero_descricao) REFERENCES GENERO(descricao)
    
);

CREATE TABLE ATOR (
	nome_real VARCHAR(200),
    PRIMARY KEY (nome_real)
);

CREATE TABLE ATOR_FILME(
	nome_ator VARCHAR(200),
    id_filme INTEGER,
    PRIMARY KEY(nome_ator, id_filme),
    FOREIGN KEY (nome_ator) REFERENCES ATOR(nome_real),
	FOREIGN KEY (id_filme) REFERENCES FILME(id)
);

CREATE TABLE CLIENTE (
	num INTEGER,
    nome VARCHAR(100),
    sobrenome VARCHAR(100),
    telefone VARCHAR(11),ator
    endereco VARCHAR(300),
    PRIMARY KEY (num)
);

CREATE TABLE DVD (
	id INTEGER,
    id_filme INTEGER,
    num_cliente INTEGER,
	data_devolucao DATE,
    data_emprestimo DATE,
    valor_pago FLOAT(10, 2),
    valor_a_pagar FLOAT(10, 2),
    PRIMARY KEY (id),
    FOREIGN KEY (id_filme) REFERENCES FILME(id),
    FOREIGN KEY (num_cliente) REFERENCES CLIENTE(num)
);