USE pet_adopt;

INSERT INTO FUNCIONARIO(nome, cpf, pis) VALUES
('Luís Thomas Carvalho', '50478290900', '58251431500'),
('Malu Rosângela Baptista', '78593944990', '31786218665'),
('Caroline Eliane Jesus', '16783116930', '25992426222'),
('Helena Hadassa Allana Cavalcanti', '81849437092', '02680133700'),
('Débora Betina Peixoto', '44671695987', '86301794135'),
('Edson Mário da Mata', '79125623974', '51888927147'),
('Giovanni André Osvaldo Campos', '65753667910', '85548029481'),
('Elias Carlos Nicolas dos Santos', '43986387927', '97407024207'),
('Catarina Jéssica Caldeira', '42463860901', '50058854580'),
('Bento Arthur Anthony Alves', '87269800960', '52853713084'),
('Manuel Benedito da Rocha', '82784453979', '36288494955'),
('Fátima Lavínia Rocha', '39688425966', '26149089914'),
('Gabrielly Cristiane Aparecida Martins', '07853675941', '62998411272'),
('Bárbara Márcia Sara Drumond', '11168581931', '62998411272'),
('Esther Melissa Marina Fogaça', '44101262969', '84952462509'),
('Alessandra Teresinha da Cruz', '07126704917', '87684678158'),
('Sarah Emanuelly Raquel Araújo', '56181313907', '11866727383'),
('Luís Levi Freitas', '93962787933', '57499475619'),
('Benedito Pedro Oliver Jesus', '52538729904', '78235227575'),
('Enzo Henrique Hugo Barbosa', '48034831913', '04974617108'),
('Benedito Oliver Carlos Eduardo Drumond', '90105909920', '52853713084'),
('Severino Ryan Iago Monteiro', '63069532993', '14677877560'),
('André Bruno Ramos', '84798550965', '54073226083'),
('Eduardo Tomás da Rocha', '16544278963', '32829685748'),
('Sueli Alessandra Isabelle Galvão', '30987004913', '36760150541'),
('Aline Francisca Fogaça', '96785859956', '01955811196'),
('Priscila Camila Bianca Porto', '45730706995', '09485930971'),
('Amanda Tereza Aparício', '53304143939', '11406696042'),
('Liz Emanuelly Olivia Dias', '63440994961', '53609280598'),
('Jéssica Mariah Sales', '09901450934', '58846609152');


INSERT INTO ESTAGIARIO(cpf, inicio_exp, fim_exp, turno) VALUES
('82784453979', '2020-12-01', '2021-05-01', 'matutino'),
('39688425966', '2021-01-01', '2021-06-01', 'vespertino'),
('07853675941', '2021-02-02', '2021-07-02', 'vespertino'),
('11168581931', '2021-03-25', '2021-09-25', 'vespertino'),
('44101262969', '2021-04-10', '2021-10-10', 'matutino'),
('07126704917', '2021-02-25', '2021-08-25', 'vespertino'),
('56181313907', '2021-03-20', '2021-09-20', 'noturno'),
('93962787933', '2021-03-01', '2021-09-01', 'matutino'),
('52538729904', '2021-05-17', '2021-11-17', 'noturno'),
('48034831913', '2021-01-05', '2021-07-05', 'matutino');


INSERT INTO RECEPCIONISTA(cpf, telefone) VALUES
('09901450934', '44986505092'),
('63440994961', '44998871380'),
('53304143939', '44997122590'),
('45730706995', '44996886707'),
('96785859956', '44996794198'),
('30987004913', '44994302611'),
('16544278963', '44991540694'),
('84798550965', '44995812490'),
('63069532993', '44984394399'),
('90105909920', '44987220490');


INSERT INTO VETERINARIO(cpf, crmv_uf, dia_plantao, horas_plantao) VALUES
('50478290900', 'PR', 'segunda-feira', 12),
('78593944990', 'PR', 'terça-feira', 6),
('16783116930', 'PR', 'quarta-feira', 12),
('81849437092', 'PR', 'quinta-feira', 6),
('44671695987', 'PR', 'sexta-feira', 12),
('79125623974', 'PR', 'sabado', 6),
('65753667910', 'PR', 'domingo', 12),
('43986387927', 'PR', 'sabado', 6),
('42463860901', 'PR', 'quinta-feira', 6),
('87269800960', 'PR', 'terça-feira', 6);


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
('43567143182', 'Manoel Edson Baptista',  '44997811987', 'União', 334),
('11293381187', 'Sérgio Bento Cardoso', '44992871837', 'Ceará Mirim', 444),
('25512706420', 'Rosângela Lara Stefany Corte Real', '44981070790', 'Nilza', 610),
('57837528603', 'Yago Bento Osvaldo Rezende', '44997005362', 'Pedro Siqueira', 398),
('47557183410', 'Marcelo Kaique Lucas Bernardes', '44982074022', 'Maracá', 147),
('61578070325', 'Raquel Pietra Yasmin Assis', '44988334932', 'Doutor Viriato de Medeiros', 988),
('06949442629', 'Thomas Fábio Mendes', '44981407457', 'Euclides Gomes da Silva', 741),
('18525973807', 'Gael Cauã Pedro Henrique Ferreira', '44987055173', 'Paulo do Espirito Santo Silva', 771),
('05510027436', 'Ester Marlene Tatiane da Cunha', '44991543514', 'Santa Gertrudes', 488),
('34098340879', 'Igor Lucca Paulo Gonçalves', '44993761378', 'Angico', 652);


INSERT INTO RECEP_ATEND_CLIENTE(cpf_cliente, cpf_recep) VALUES
('43567143182', '53304143939'),
('61578070325', '53304143939'),
('47557183410', '53304143939'),
('57837528603', '30987004913'),
('47557183410', '16544278963'),
('61578070325', '84798550965'),
('06949442629', '63069532993'),
('18525973807', '90105909920'),
('05510027436', '90105909920'),
('34098340879', '90105909920');


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
('Dora', '2021-02-06', 'femea', 'Pastor alemão', '57837528603'),
('Pit', '2018-12-30', 'femea', 'Lhasa apso', '61578070325'),
('Cebola', '2018-03-28', 'macho', 'Husky siberiano', '06949442629'),
('Lup', '2015-12-01', 'macho', 'Pequinês', '18525973807'),
('Jack', '2014-03-25', 'macho', 'Rottweiler', '05510027436'),
('Fred', '2019-04-25', 'macho', 'Dálmata', '34098340879');


INSERT INTO TIPO(nome, descricao, nivel_gravidade) VALUES
('Diagnostico por Imagem', 'Atendimento fundamental para a realização de diagnósticos precisos.', 'baixo'),
('Coleta de Exame', 'Atendimento para coletar exames necessários.', 'baixo'),
('Dermatologico', 'Atendimento para diagnosticar problemas e patologias dos mais diversos.', 'baixo'),
('Cirúrgico', 'Atendimentos que necessitam de cirurgia.', 'medio'),
('Odontológico', 'Atendimentos direcionado para a saúde bucal do cachorro.', 'baixo'),
('Cardiologico', 'Atendimento para tratar problemas relacionado ao sistema cardiovascular do cachorro.', 'alto'),
('Oftalmo', 'Atendimento direcionado ao tratamento da visão do cachorro.', 'medio'),
('Curativo', 'Atendimento realizado para aplicar um curativo, ou tratar alguma lesão.', 'baixo'),
('Desintoxicação', 'Atendimento parar desintoxicar o cachorro.', 'alto'),
('Emergêncial', 'Atendimentos com urgencia extrema.', 'alto');


INSERT INTO ATENDIMENTO (data_aten, custo, descricao, id_cachorro, tipo, cpf_veterinario) VALUES
('2021-04-02', 103.4, 'O cachorro apresentava uma quantidade preocupante de tartaro em seus dentes.', 9, 'Odontológico', '50478290900'),
('2021-03-22', 1000, 'O cachorro estava com uma ferida muito grave na região do seu tórax.', 4, 'Emergêncial', '43986387927'),
('2021-01-25', 3.5, 'O cachorro necessitou de um pequeno curativo em sua orelha.', 3, 'Curativo', '81849437092'),
('2021-01-01', 30.2, 'O cachorro precisou passar por uma coleta de sangue para verificar sua saúde.', 1, 'Coleta de Exame', '87269800960'),
('2021-02-21', 40.78, 'O cachorro necessitou de curativos na região de sua barriga.', 2, 'Curativo', '44671695987'),
('2021-05-14', 350, 'O cachorro apresentou sintomas de intoxicação alimentar.', 6, 'Desintoxicação', '50478290900'),
('2021-05-11', 600, 'Foi necessário um raio-x para verificar o estado da saúde do cachorro.', 6, 'Diagnostico por Imagem', '79125623974'),
('2021-05-01', 800, 'Apresentou problemas serios em seu sistema urinario.', 7, 'Cirúrgico', '50478290900'),
('2021-04-29', 100, 'Nosso objetivo é identificar se o cachorro possui sarna.', 8, 'Dermatologico', '65753667910'),
('2021-04-14', 780, 'Necessário pois o cachorro é muito velho, então devemos monitorar sua saúde.', 9, 'Cardiologico', '50478290900');


INSERT INTO RACAO(marca, kg_pacote, valor_kg) VALUES
("AuAu Dog's", 50,10),
("HotMeat Dog's", 20,11.5),
("Basic Dog's", 50,5),
("Premium Dog's", 15,25),
("Elementary Dog's", 10,15),
("Poor Dog's", 100,3.5),
("Milk Dog's", 50,8.4),
("PrettyHair Dog's", 20,19.5),
("CareSkin Dog's", 18,20),
("PuppyDog's", 30,17.5);


INSERT INTO ESTAG_COMPRA_RACAO(marca_racao, qtd_pacote, cpf_estag) VALUES
("Poor Dog's", 1,'82784453979'),
("Poor Dog's", 3,'48034831913'),
("Poor Dog's", 10,'56181313907'),
("PuppyDog's", 5,'07853675941'),
("HotMeat Dog's", 1,'07853675941'),
("CareSkin Dog's", 3,'56181313907'),
("AuAu Dog's", 5,'93962787933'),
("Elementary Dog's", 2,'52538729904'),
("Poor Dog's", 3,'39688425966'),
("PrettyHair Dog's", 3,'39688425966');

