USE escola;

# Encontre os nomes de todos os Juniors (nível = JR) 
#que estão matriculados em um curso ministrado por Ivana Teach.

SELECT A.nomeAlun
FROM ALUNO A, CURSO C, MATRICULADO M, PROFESSOR P
WHERE A.nivel = 'JR'
	AND A.nroAlun = M.nroAlun
    AND M.nomeCurso = C.nome
    AND C.idProf = P.idProf
    AND P.nomeProf = 'Ivana Teach';
    

# Encontre a idade do aluno mais velho que é formado em History ou matriculado em um curso ministrado por Ivana Teach.
SELECT MAX(A.idade) AS max_idade
FROM ALUNO A
WHERE A.formacao = 'History'
OR A.nroAlun IN (
	SELECT M.nroAlun 
    FROM MATRICULADO M, CURSO C, PROFESSOR P, ALUNO A2
    WHERE M.nroAlun = A2.nroAlun
    AND M.nomeCurso = C.nome
    AND P.nomeProf = 'Ivana Tech'
);


# Encontre os nome de todos os cursos que são ministrados na sala R128 ou que têm cinco ou mais alunos matriculados.
SELECT C.nome
FROM CURSO C
WHERE C.sala = 'R128'
OR C.nome IN (
	SELECT M.nomeCurso
    FROM MATRICULADO M
    GROUP BY M.nomeCurso
    HAVING COUNT(*) >= 5
);

# Encontre os nomes de todos os alunos que estão matriculados em dois cursos que são ministrados no mesmo horário.ALTER

SELECT DISTINCT A.nomeAlun
FROM ALUNO A
WHERE A.nroAlun IN (
	SELECT M1.nroAlun
    FROM MATRICULADO M1, MATRICULADO M2, CURSO C1, CURSO C2
    WHERE M1.nomeCurso = C1.nome
    AND M2.nomeCurso = C2.nome
    AND M1.nroAlun = M2.nroAlun
    AND C1.nome <> C2.nome
    AND C1.horario = C2.horario
);


#Encontre os nomes dos professores que ministram cursos em todas as salas em que algum curso é ministrado.


#Imprima o nível e a idade média dos alunos desse nível, para cada nível.
SELECT A.nivel, AVG(A.idade) AS idade_media
FROM ALUNO A
GROUP BY A.nivel;



