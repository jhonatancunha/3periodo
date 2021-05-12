DROP DATABASE IF EXISTS pet_adopt;
CREATE DATABASE pet_adopt;
USE pet_adopt;


CREATE TABLE FUNCIONARIO (
	nome VARCHAR(100),
    cpf CHAR(11),
    pis CHAR(11),
    PRIMARY KEY (cpf)
);

CREATE TABLE RECEPCIONISTA (
	cpf VARCHAR(100),
    telefone VARCHAR(11),
    PRIMARY KEY (cpf),
    FOREIGN KEY (cpf)
		REFERENCES FUNCIONARIO(cpf)
        ON DELETE CASCADE
);

CREATE TABLE ESTAGIARIO (
	cpf VARCHAR(100),
    inicio_exp DATE,
    fim_exp DATE,
    turno ENUM('matutino', 'vespertino', 'noturno'),
    PRIMARY KEY (cpf),
    FOREIGN KEY (cpf)
		REFERENCES FUNCIONARIO(cpf)
        ON DELETE CASCADE
);



CREATE TABLE CLIENTE (
	cpf VARCHAR(11),
    nome VARCHAR(100),
    telefone VARCHAR(11),
    PRIMARY KEY (cpf)
);

CREATE TABLE ENDERECO (
	rua VARCHAR (100),
	logradouro VARCHAR(50),
    numero INTEGER,
    complemento VARCHAR(200),
    PRIMARY KEY(rua, numero)
);

CREATE TABLE CACHORRO (
	id INTEGER NOT NULL AUTO_INCREMENT,
	nome VARCHAR(100),
    data_nasc DATE,
    sexo ENUM('macho','femea'),
    PRIMARY KEY (id)
);

CREATE TABLE RACA (
	nome VARCHAR(100),
    porte ENUM('mini', 'P', 'M', 'G'),
    nivel_cuidado ENUM('baixo', 'medio' ,'alto'),
    caracteristica VARCHAR(200),
    PRIMARY KEY(nome)
);

CREATE TABLE ATENDIMENTO (
	id INTEGER NOT NULL AUTO_INCREMENT,
    data_aten DATE,
    custo FLOAT(10, 2),
    descricao VARCHAR(300),
    PRIMARY KEY (id)
);

CREATE TABLE TIPO (
	nome VARCHAR(100),
    descricao VARCHAR(300),
    nivel_gravidade ENUM('baixo','medio','alto'),
    PRIMARY KEY (nome)
);


