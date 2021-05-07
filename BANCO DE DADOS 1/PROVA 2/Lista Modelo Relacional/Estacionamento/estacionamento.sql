DROP DATABASE IF EXISTS escola2;
CREATE DATABASE escola2;
USE escola2;


CREATE TABLE VAGAS (
    ID INTEGER,
    VAGA_STATUS BOOL NOT NULL,
    PRIMARY KEY (ID)
);

CREATE TABLE VAGA_AVULSA(
	ID_VAGA INTEGER,
	CUSTO_HORA_CARRO FLOAT(5, 2),
    CUSTO_HORA_MOTO FLOAT(5, 2),
	PRIMARY KEY(ID_VAGA),
    FOREIGN KEY (ID_VAGA) 
		REFERENCES VAGAS(ID)
		ON DELETE CASCADE
);

CREATE TABLE VAGA_MENSAL(
	ID_VAGA INTEGER,
	CUSTO_MENSAL_CARRO FLOAT(5, 2),
    CUSTO_MENSAL_MOTO FLOAT(5, 2),
	PRIMARY KEY(ID_VAGA),
    FOREIGN KEY (ID_VAGA) 
		REFERENCES VAGAS(ID)
		ON DELETE CASCADE
);

CREATE TABLE CLIENTE(
	CPF CHAR(11),
    NOME VARCHAR(100),
    PRIMARY KEY(CPF)
);

CREATE TABLE ESTACIONAGEM(
	ID INTEGER,
    ID_VAGA INTEGER,
    CPF_CLIENTE CHAR(11),
    DATA_HORA_SAIDA DATETIME,
    DATA_HORA_ENTRADA DATETIME,
    PLACA CHAR(7),
    CUSTO FLOAT(5, 2),
    PRIMARY KEY(ID),
    FOREIGN KEY (ID_VAGA) REFERENCES VAGAS(ID),
    FOREIGN KEY (CPF_CLIENTE) REFERENCES CLIENTE(CPF)
);

CREATE TABLE VAGA_MENSAL_CLIENTE(
	CPF_CLIENTE CHAR(11),
    ID_VAGA_MENSAL INTEGER,
    PRIMARY KEY(CPF_CLIENTE, ID_VAGA_MENSAL),
    FOREIGN KEY(CPF_CLIENTE) REFERENCES CLIENTE(CPF),
    FOREIGN KEY(ID_VAGA_MENSAL) REFERENCES VAGA_MENSAL(ID_VAGA)
);
