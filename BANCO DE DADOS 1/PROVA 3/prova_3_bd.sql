DROP DATABASE IF EXISTS prova3;
CREATE DATABASE prova3;
USE prova3;

CREATE TABLE DISCIPLINA(
  nome VARCHAR(100) PRIMARY KEY,
  preRequisito VARCHAR(100),
  FOREIGN KEY(preRequisito) REFERENCES DISCIPLINA(nome)
);

CREATE TABLE ALUNO(
   id INTEGER PRIMARY KEY,
   nome VARCHAR(100)
);

CREATE TABLE PROFESSOR(
   id INTEGER PRIMARY KEY,
   nome VARCHAR(100)
);

CREATE TABLE TURMA(
   ano INTEGER,
   nomeDisciplina VARCHAR(100),
   professor INTEGER,
   PRIMARY KEY (nomeDisciplina,ano),
   FOREIGN KEY(nomeDisciplina) REFERENCES DISCIPLINA(nome),
   FOREIGN KEY(professor) REFERENCES PROFESSOR(id)
);

CREATE TABLE MATRICULA(
    idAluno INTEGER PRIMARY KEY,
    nomeDisciplina VARCHAR(100),
    ano INTEGER,
    nota DECIMAL(10,2),
    FOREIGN KEY(nomeDisciplina, ano) REFERENCES TURMA(nomeDisciplina, ano),
    FOREIGN KEY(idAluno) REFERENCES ALUNO(id)
);

#Escreva uma consulta em SQL que selecione os alunos sem repetição dos cursos de 2020.
SELECT DISTINCT A.nome
FROM ALUNO A, MATRICULA M
WHERE M.idAluno = A.id
AND M.ano = 2020;


# Escreva uma consulta em SQL que liste as disciplinas sem pré-requisitos que foram ofertadas entre 2010 e 2020.
SELECT D.nome
FROM DISCIPLINA D, MATRICULA M
WHERE M.nomeDisciplina = D.nome
AND D.preRequisito IS NULL
AND M.ano >= 2010 AND M.ano <= 2020;


# Escreva uma consulta em SQL que liste o nome dos alunos e a quantidade de matriculas realizadas.
SELECT A.nome, COUNT(*) AS matriculas_realizadas
FROM ALUNO A, MATRICULA M
WHERE A.id = M.idAluno
GROUP BY A.nome;


# Escreva uma consulta em SQL que exiba os alunos que NÃO fizeram nenhuma disciplina em 2020.
SELECT A.nome
FROM ALUNO A, MATRICULA M
WHERE A.id = M.idAluno
AND A.nome NOT IN (
	SELECT DISTINCT A2.nome
	FROM ALUNO A2, MATRICULA M2
	WHERE M2.idAluno = A2.id
	AND M2.ano = 2020
); 

# Escreva uma consulta em SQL que exiba a média dos alunos das disciplinas que foram ofertadas mais dos 10 vezes.
SELECT AVG(M.nota)
FROM MATRICULA M, ALUNO A
WHERE M.idAluno = A.id
GROUP BY M.nomeDisciplina
HAVING COUNT(M.nomeDisciplina) > 10;


# Escreva uma consulta em Álgebra Relacional 
# que exiba os professores que ministraram as disciplinas em 2020 
# e que não ministraram Banco de Dados.







