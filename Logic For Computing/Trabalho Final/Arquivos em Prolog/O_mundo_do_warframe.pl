
% ########## Declarando os Fatos ##########


% ---Personagens---

personagem("Balla").
personagem("Kalli").
personagem("Sentients").
personagem("Tenno").
personagem("Hunhow").
personagem("Natah/Lotus").
personagem("Capitão Vor").

% ---Faccoes---

faccao("grineer").
faccao("corpus").
faccao("infestado").
faccao("sentient").

% ---Regioes onde vivem---
% vivem_em(faccao, planeta) -> é um predicado que indica onde cada
% faccao tem o dominio


vivem_em(grineers, terra).
vivem_em(grineers, marte).
vivem_em(grineers, ceres).
vivem_em(grineers, saturno).
vivem_em(grineers, urano).
vivem_em(grineers, mercurio).
vivem_em(grineers, sedna).
vivem_em(corpus, phobos).
vivem_em(corpus, venus).
vivem_em(corpus, plutao).
vivem_em(corpus, netuno).
vivem_em(corpus, jupiter).
vivem_em(corpus, europa).
vivem_em(infestados, eris).
vivem_em(infestados, deimos).

% ---Chefões dos Planetas---


boss(cpt_vor, mercurio).
boss(jackal, venus).
boss(vay_hek, terra).
boss(lech_krill, marte).
boss(sangent, phobos).
boss(lech_krill_and_cpt_vor, ceres).
boss(alad_v, jupiter).
boss(raptors, europa).
boss(sargas_ruk, saturno).
boss(tyl_regor, urano).
boss(hyena_pack, netuno).
boss(ambulas, plutao).
boss(kela_de_thaym, sedna).
boss(alad_v_infestado, eris).

% ---Waframes drops---

dropa_em(rhino,venus).
dropa_em(hydroid, terra).
dropa_em(excalibur, marte).
dropa_em(mag, phobos).
dropa_em(frost, ceres).
dropa_em(valkyr, jupiter).
dropa_em(nova, europa).
dropa_em(ember, saturno).
dropa_em(equinox, urano).
dropa_em(loki, netuno).
dropa_em(trinity, plutao).
dropa_em(saryn, sedna).
dropa_em(mesa, eris).
dropa_em(nekros, deimos).

% ---Recursos drops---

dropa(mercurio, morfico).
dropa(marte, morfico).
dropa(plutao, morfico).
dropa(europa, morfico).
dropa(phobos, morfico).
dropa(mercurio, ferrite).
dropa(terra, ferrite).
dropa(netuno, ferrite).
dropa(mercurio, polimero).
dropa(venus, polimero).
dropa(urano, polimero).
dropa(mercurio, ampola_detonite).
dropa(saturno, ampola_detonite).
dropa(urano, ampola_detonite).
dropa(terra, ampola_detonite).
dropa(sedna, ampola_detonite).
dropa(ceres, ampola_detonite).
dropa(venus, chapa_metalica).
dropa(jupiter, chapa_metalica).
dropa(ceres, chapa_metalica).
dropa(sedna, chapa_metalica).
dropa(plutao, chapa_metalica).
dropa(phobos, chapa_metalica).
dropa(venus, circuitos).
dropa(ceres, circuitos).
dropa(venus, amostra_de_fieldron).
dropa(jupiter, amostra_de_fieldron).
dropa(marte, amostra_de_fieldron).
dropa(europa, amostra_de_fieldron).
dropa(netuno, amostra_de_fieldron).
dropa(plutao, amostra_de_fieldron).
dropa(terra, rubedo).
dropa(plutao, rubedo).
dropa(sedna, rubedo).
dropa(europa, rubedo).
dropa(phobos, rubedo).
dropa(terra, neurodes).
dropa(eris, neurodes).
dropa(deimos, neurodes).
dropa(marte, restos).
dropa(jupiter, restos).
dropa(sedna, restos).
dropa(marte, galio).
dropa(urano, galio).
dropa(saturno, celula_orokin).
dropa(ceres, celula_orokin).
dropa(deimos, celula_orokin).
dropa(jupiter, hexeno).
dropa(jupiter, sensores_neurais).
dropa(netuno, modulo_de_controle).
dropa(europa, modulo_de_controle).
dropa(saturno, nano_esporos).
dropa(netuno, nano_esporos).
dropa(eris, nano_esporos).
dropa(deimos, nano_esporos).
dropa(saturno, plastideos).
dropa(urano, plastideos).
dropa(plutao, plastideos).
dropa(eris, plastideos).
dropa(phobos, plastideos).
dropa(deimos, amostra_mutagenica).
dropa(eris, amostra_mutagenica).

% ---Dark Sector's---

darkSector(coba, defesa, terra).
darkSector(wahiba, sobrevivencia, marte).
darkSector(gabi, sobrevivencia, ceres).
darkSector(piscinas, sobrevivencia, saturno).
darkSector(ur, interferencia, urano).
darkSector(amara, sobrevivencia, sedna).
darkSector(memphis, desercao, phobos).
darkSector(romula, defesa, venus).
darkSector(hieracon, escavacao, plutao).
darkSector(kelashin, sobrevivencia, netuno).
darkSector(sinai, defesa, jupiter).
darkSector(cholistan, escavacao, europa).
darkSector(zabala, sobrevivencia, eris).

% ---Melhores locais de farm de recursos---

farm(polimero, ophelia, urano).
farm(celula_orokin, pallas, ceres).
farm(nano_esporos, kelashin, netuno).
farm(ferrite, coba, terra).
farm(chapa_metalica, adaro, sedna).
farm(rubedo, adaro, sedna).
farm(galio, ophelia, urano).
farm(sensores_neurais, themisto, jupter).
farm(plastideos, piscinas, saturno).
farm(restos, adaro, sedna).
farm(hexeno, io, jupter).
farm(morfico, hieracon, netuno).
farm(ampola_detonite, adaro, sedna).
farm(amostra_de_fieldron, kelashin, netuno).
farm(amostra_mutagenica, zabala, eris).



% ---Tipo de armadura---

armadura(grineers, ferrite).
armadura(corpus, aloy).
armadura(infestados, technosyte).


% ---Fraquezas---

fraqueza(ferrite, corrosivo).
fraqueza(aloy, radiacao).
fraqueza(technosyte, gas).


%---Armas---


weapon(cpt_vor, snipers).
weapon(jackal, shotguns).
weapon(vay_hek, armas_de_feixe).
weapon(lech_krill, ignis).
weapon(sangent, rubico).
weapon(lech_krill_and_cpt_vor, ignis).
weapon(alad_v, rubico/snipers).
weapon(raptors, snipers).
weapon(sargas_ruk, tigris/shotguns).
weapon(tyl_regor, khom/shotguns).
weapon(hyena_pack, snipers).
weapon(ambulas, meeles_pesadas).
weapon(kela_de_thaym, ignis).
weapon(alad_v_infestado, armas_de_feixe).


% ---Dominios gerais ---

dominava(tenno, transferencia).
dominava(orokins, tenno).
dominava(corpus, tecnologia).
dominava(orokins, corpus).
dominava(grinners, minerios).
dominava(orokins, grinners).
dominava(tenno, warframes).
dominava(corpus, sentients).
dominava(grinners, chaves_do_dragao).


% ################### Declarando as Regras #########################



% ---Locais de drop de Waframes e Recursos---

drop(X, Y) :-
    dropa(Y, X); dropa_em(X, Y).


% ---Boss que eh preciso lutar para farmar as partes do warframe---

boss_necessario(X, W, Z):-
    dropa_em(X, Z), boss(W, Z).

% ---Fraquezas dos Bosses (dano que será preciso ter na arma)---

dano(X, W) :-
    boss(X, Z), vivem_em(U, Z), armadura(U, V), fraqueza(V, W).



% ---Fatos historicos do jogo---

controlava(X, Y):- dominava(X, Y).
controlava(X, Y):-
    dominava(X, Z), controlava(Z, Y).



