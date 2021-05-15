USE pet_adopt;

INSERT INTO ENDERECO(rua, tipo_logradouro, numero, complemento) VALUES
('União', 'Avenida', 334, 'Casa'),
('Ceará Mirim', 'Rua', 444, 'Apartamento 202'),
('Nilza', 'Rua', 610, 'Apartamento 403'),
('Pedro Siqueira', 'Rua', 398, 'Casa'),
('Maracá', 'Rua', 147, 'Casa Fundo'),
('Doutor Viriato de Medeiros', 'Praça', 988, 'Apartamento 420'),
('Euclides Gomes da Silva', 'Rua', 741, 'Casa Frente'),
('Paulo do Espirito Santo Silva', 'Avenida', 771, 'Apartamento 112'),
('Santa Gertrudes', 'Rua', 488, 'Casa'),
('Angico', 'Rua', 652, 'Casa');

INSERT INTO CLIENTE(cpf, nome, telefone, end_rua, end_numero) VALUES
('43567143182', 'Manoel Edson Baptista',  '86997811987', 'União', 334),
('11293381187', 'Sérgio Bento Cardoso', '21992871837', 'Ceará Mirim', 444),
('25512706420', 'Rosângela Lara Stefany Corte Real', '21981070790', 'Nilza', 610),
('57837528603', 'Yago Bento Osvaldo Rezende', '96997005362', 'Pedro Siqueira', 398),
('47557183410', 'Marcelo Kaique Lucas Bernardes', '21982074022', 'Maracá', 147),
('61578070325', 'Raquel Pietra Yasmin Assis', '85988334932', 'Doutor Viriato de Medeiros', 988),
('06949442629', 'Thomas Fábio Mendes', '95981407457', 'Euclides Gomes da Silva', 741),
('18525973807', 'Gael Cauã Pedro Henrique Ferreira', '96987055173', 'Paulo do Espirito Santo Silva', 771),
('05510027436', 'Ester Marlene Tatiane da Cunha', '86991543514', 'Santa Gertrudes', 488),
('34098340879', 'Igor Lucca Paulo Gonçalves', '69993761378', 'Angico', 652);


INSERT INTO RACA(nome, nivel_cuidado, porte, caracteristica) VALUES 
('Akita', 'alto', 'G', 'leal'),
('Pinscher', 'medio', 'P', 'brincalhão'),
('Pug', 'alto', 'P', 'amoroso'),
('Yorkshire', 'medio', 'P', 'destemido'),
('Pastor alemão', 'alto', 'G', 'inteligente'),
('Lhasa apso', 'medio', 'P', 'esperto'),
('Husky siberiano', 'medio', 'G', 'trabalhador'),
('Pequinês', 'medio', 'P', 'afetuoso'),
('Rottweiler', 'alto', 'G', 'protetor'),
('Dálmata', 'medio', 'G', 'atlético');

INSERT INTO CACHORRO(nome, data_nasc, sexo, nome_raca, cpf_cliente) VALUES
('Bob', '2016-12-02', 'macho', 'Akita', '43567143182'),
('Mel', '2018-05-23', 'femea', 'Pinscher', '11293381187'),
('Nina', '2020-06-01', 'femea', 'Pug', '25512706420'),
('Marley', '2021-01-01', 'macho', 'Yorkshire', '57837528603'),
('Dora', '2021-02-06', 'femea', 'Pastor alemão', '47557183410'),
('Pit', '2018-12-30', 'femea', 'Lhasa apso', '61578070325'),
('Cebola', '2018-03-28', 'macho', 'Husky siberiano', '06949442629'),
('Lup', '2015-12-01', 'macho', 'Pequinês', '18525973807'),
('Jack', '2014-03-25', 'macho', 'Rottweiler', '05510027436'),
('Fred', '2019-04-25', 'macho', 'Dálmata', '34098340879');




