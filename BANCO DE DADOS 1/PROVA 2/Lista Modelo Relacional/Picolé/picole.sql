DROP DATABASE IF EXISTS picole;
CREATE DATABASE picole;
USE picole;

CREATE TABLE PICOLE(
	sabor VARCHAR(20),
    preco FLOAT(10,2),
    PRIMARY KEY (sabor)
);

CREATE TABLE INGREDIENTE(
	nome VARCHAR(100),
    sabor_picole VARCHAR(20),
    PRIMARY KEY(nome),
    FOREIGN KEY(sabor_picole) REFERENCES PICOLE(sabor)
);

CREATE TABLE EMBALAGEM(
	nome VARCHAR(100),
	sabor_picole VARCHAR(20),
    PRIMARY KEY(nome),
    FOREIGN KEY(sabor_picole) REFERENCES PICOLE(sabor)
);

CREATE TABLE PICOLE_LEITE(
	nome_sabor VARCHAR(20),
    PRIMARY KEY(nome_sabor),
    FOREIGN KEY(nome_sabor) REFERENCES PICOLE(sabor)
);

CREATE TABLE PICOLE_NORMAL(
	nome_sabor VARCHAR(20),
    PRIMARY KEY(nome_sabor),
    FOREIGN KEY(nome_sabor) REFERENCES PICOLE(sabor)
);

CREATE TABLE ADITIVOS_NUTRITIVOS(
	nome VARCHAR(100),
    formula VARCHAR(200),
    PRIMARY KEY(nome)
);

CREATE TABLE NORMAL_ADITIVOS(
	nome_aditivo VARCHAR(100),
    sabor_picole VARCHAR(20),
    PRIMARY KEY(nome_aditivo, sabor_picole),
    FOREIGN KEY(nome_aditivo) REFERENCES ADITIVOS_NUTRITIVOS(nome),
    FOREIGN KEY(sabor_picole) REFERENCES PICOLE(sabor)
);

CREATE TABLE CONSERVANTES(
	nome VARCHAR(100),
    descricao VARCHAR(200),
    PRIMARY KEY (nome)
);

CREATE TABLE LEITE_CONSERVANTE(
	nome_conservante VARCHAR(100),
    sabor_picole VARCHAR(20),
    PRIMARY KEY(nome_conservante, sabor_picole),
    FOREIGN KEY(nome_conservante) REFERENCES CONSERVANTES(nome),
    FOREIGN KEY(sabor_picole) REFERENCES PICOLE(sabor)
);

CREATE TABLE LOTE_EXCLUSIVO(
	id INTEGER,
    PRIMARY KEY(id)
);

CREATE TABLE LOTE_NORMAL(
	id_lote INTEGER,
    PRIMARY KEY(id_lote),
    FOREIGN KEY(id_lote) REFERENCES LOTE_EXCLUSIVO(id)
);

CREATE TABLE LOTE_LEITE(
	id_lote INTEGER,
    PRIMARY KEY(id_lote),
    FOREIGN KEY(id_lote) REFERENCES LOTE_EXCLUSIVO(id)
);

CREATE TABLE PICOLE_LOTE_NORMAL(
	id_lote_normal INTEGER,
	qtde INTEGER,
    sabor_picole_normal VARCHAR(20),
    PRIMARY KEY(id_lote_normal, sabor_picole_normal),
    FOREIGN KEY(id_lote_normal) REFERENCES LOTE_NORMAL(id_lote),
    FOREIGN KEY(sabor_picole_normal) REFERENCES PICOLE_NORMAL(nome_sabor)
);

CREATE TABLE PICOLE_LOTE_LEITE(
	id_lote_leite INTEGER,
    qtde INTEGER,
    sabor_picole_leite VARCHAR(20),
    PRIMARY KEY(id_lote_leite, sabor_picole_leite),
    FOREIGN KEY(id_lote_leite) REFERENCES LOTE_LEITE(id_lote),
    FOREIGN KEY(sabor_picole_leite) REFERENCES PICOLE_LEITE(nome_sabor)
);

CREATE TABLE NOTAS(
	num INTEGER,
    id_lote INTEGER,
    descricao VARCHAR(300),
    data_nota DATETIME,
    valor FLOAT(10, 2),
    PRIMARY KEY(num),
    FOREIGN KEY(id_lote) REFERENCES LOTE_EXCLUSIVO(id)
);

CREATE TABLE REVENDEDOR(
	cnpj CHAR(14),
	id_lote INTEGER,
    razao_social VARCHAR(200),
    contato VARCHAR(11),
    PRIMARY KEY (cnpj),
	FOREIGN KEY(id_lote) REFERENCES LOTE_EXCLUSIVO(id)

);