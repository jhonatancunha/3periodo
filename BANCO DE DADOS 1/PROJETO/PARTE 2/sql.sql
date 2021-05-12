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
	cpf VARCHAR(11),
    telefone VARCHAR(11),
    PRIMARY KEY (cpf),
    FOREIGN KEY (cpf)
		REFERENCES FUNCIONARIO(cpf)
        ON DELETE CASCADE
);

CREATE TABLE ESTAGIARIO (
	cpf VARCHAR(11),
    inicio_exp DATE,
    fim_exp DATE,
    turno ENUM('matutino', 'vespertino', 'noturno'),
    PRIMARY KEY (cpf),
    FOREIGN KEY (cpf)
		REFERENCES FUNCIONARIO(cpf)
        ON DELETE CASCADE
);

CREATE TABLE VETERINARIO(
	cpf VARCHAR(11),
    crmv INTEGER,
    dia_plantao ENUM('segunda-feira', 'terça-feira', 'quarta-feira', 'quina-feira', 'sexta-feira', 'sabado', 'domingo'),
    horas_plantao INTEGER,
	PRIMARY KEY (cpf),
    FOREIGN KEY (cpf)
		REFERENCES FUNCIONARIO(cpf)
        ON DELETE CASCADE
);

CREATE TABLE ENDERECO (
	rua VARCHAR (100),
	logradouro VARCHAR(50),
    numero INTEGER,
    complemento VARCHAR(200),
    PRIMARY KEY(rua, numero)
);

CREATE TABLE CLIENTE (
	cpf VARCHAR(11),
    nome VARCHAR(100),
    telefone VARCHAR(11),
    end_rua VARCHAR(100),
    end_numero INTEGER,
    PRIMARY KEY (cpf),
    FOREIGN KEY (end_rua, end_numero) REFERENCES ENDERECO(rua, numero)
);

CREATE TABLE RECEP_ATEND_CLIENTE(
	cpf_cliente VARCHAR(11),
    cpf_recep VARCHAR(11),
    PRIMARY KEY (cpf_cliente, cpf_recep),
    FOREIGN KEY (cpf_cliente) REFERENCES CLIENTE(cpf),
    FOREIGN KEY (cpf_recep) REFERENCES RECEPCIONISTA(cpf)
);

CREATE TABLE RACA (
	nome VARCHAR(100),
    porte ENUM('mini', 'P', 'M', 'G'),
    nivel_cuidado ENUM('baixo', 'medio' ,'alto'),
    caracteristica VARCHAR(200),
    PRIMARY KEY(nome)
);

CREATE TABLE CACHORRO (
	id INTEGER NOT NULL AUTO_INCREMENT,
	nome VARCHAR(100),
    data_nasc DATE,
    sexo ENUM('macho','femea'),
    nome_raca VARCHAR(100),
    cpf_cliente VARCHAR(11),
    PRIMARY KEY (id),
    FOREIGN KEY (nome_raca) REFERENCES RACA(nome),
	FOREIGN KEY (cpf_cliente) REFERENCES CLIENTE(cpf)
);

CREATE TABLE RACAO(
	marca VARCHAR(100),
    kg FLOAT,
    valor_kg FLOAT,
    PRIMARY KEY(marca)
);

CREATE TABLE ESTAG_COMPRA_RACAO(
	marca_racao VARCHAR(100),
    cpf_estag VARCHAR(11),
    PRIMARY KEY(marca_racao, cpf_estag),
    FOREIGN KEY (cpf_estag) REFERENCES ESTAGIARIO(cpf),
    FOREIGN KEY (marca_racao) REFERENCES RACAO(marca)
);

CREATE TABLE TIPO (
	nome VARCHAR(100),
    descricao VARCHAR(300),
    nivel_gravidade ENUM('baixo','medio','alto'),
    PRIMARY KEY (nome)
);

CREATE TABLE ATENDIMENTO (
	id INTEGER NOT NULL AUTO_INCREMENT,
    data_aten DATE,
    custo FLOAT,
    descricao VARCHAR(300),
    id_cachorro INTEGER,
    tipo VARCHAR(100),
    cpf_veterinario VARCHAR(11),
    PRIMARY KEY (id),
    FOREIGN KEY (id_cachorro) REFERENCES CACHORRO(id),
	FOREIGN KEY (tipo) REFERENCES TIPO(nome),
    FOREIGN KEY (cpf_veterinario) REFERENCES VETERINARIO(cpf)
);