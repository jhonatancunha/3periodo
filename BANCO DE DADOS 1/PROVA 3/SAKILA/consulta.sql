/* 1 - Liste o título de todos os filmes. */

SELECT titulo
FROM FILME;

/* 2 - Liste o nome de todos os Atores. */

SELECT nome
FROM ATOR;

/* 3 - Imprima os filmes que tem "SQL" em alguma parte da descrição. */

SELECT descricao
FROM FILME
WHERE descricao LIKE '%SQL%';

/* 4 - Liste todos filmes que foram lancados em 2006.*/

SELECT *
FROM FILME
WHERE ano_lancamento = '2006';

/* 5 - Liste todos os Atores que participaram do filme KING EVOLUTION */

SELECT A.nome
FROM FILME_ATOR AS FA, FILME AS F, ATOR AS A
WHERE	F.ID = FA.id_filme
		AND FA.id_ator = A.id
		AND F.TITULO = 'KING EVOLUTION';

/* 6 - Mostre a avalição dos filmes em que a idioma é "Japanese". */

/* 7 - Mostre todos os filmes da categoria "Comedy" que tem como idioma "Italian". */

/* 8 - Encontre os nomes de todos atores que participaram de dois filmes 
que possuem o meesmo idioma. */


