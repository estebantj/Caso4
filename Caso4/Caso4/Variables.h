#pragma once

#ifndef Variables_H
#define Variables_H
//
#include <unordered_set>
#include <string>

// Pronombres, adverbios...
const std::unordered_set <std::wstring> filtro
({ L"el",L"al",L"la",L"lo",L"los",L"las",L"un",
	L"una",L"unos",L"unas",L"y",L"a",L"ante",L"bajo",
	L"cabe",L"con",L"contra",L"de",L"desde",L"durante",
	L"en",L"entre",L"hacia",L"hasta",L"mediante",L"para",
	L"por",L"seg�n",L"sin",L"e",L"sobre",L"tras",L"versus",
	L"v�amucho",L"muchos",L"mucha", L"muchas",L"",L"pocos",
	L"poca",L"pocas",L"tanto",L"tantos",L"tanta",L"tantas",
	L"bastante",L"bastantes",L"demasiada",L"demasiadas",L"alguno",L"s�",
	L"algunos",L"alguna",L"algunas",L"ninguno",	L"ninguna",L"algo",L"es",
	L"nada",L"qu�",L"qui�n",L"qui�nes",L"cu�l",L"cu�les", L"cu�nto",L"fue",
	L"cu�ntos",L"cu�nta",L"cu�ntas",L"d�nde",L"c�mo",L"cuyo",L"cuyos",L"surgi�",
	L"cuyas",L"cuya",L"donde",L"quien",L"quienes",L"este",L"ese",L"aqu�l",L"esta",
	L"probablemente",L"seguramente",L"cu�ndo",L"cu�n",L"ojal�",L"cu�nto",L"cu�nta"
	L"esa",L"aquella",L"estos",L"esos",L"aquellos",L"estas",L"esas",L"aquellas",L"esto",
	L"eso",L"aquello",L"mi",L"mis",L"m�o",L"m�a",L"m�osm�as",L"tu",L"tus",L"tuyo",L"tuya",
	L"tuyos",L"tuyas",L"su",L"sus",L"suyo",L"suya",L"suyos",L"suyas",L"nuestro",L"nuestra",
	L"nuestros",L"nuestras",L"vuestro",L"vuestra",L"vuestros",L"vuestras",L"yo",L"t�",L"�l",
	L"cerca",L"lejos",L"encima",L"fuera",L"bien",L"regular",L"despacio",L"as�",L"mejor",L"peor",
	L"usted",L"ustedes",L"nosotros",L"nosotras",L"vosotros",L"vosotras",L"ellos",L"ellas", L"me",
	L"te",L"nos",L"se",L"ya",L"a�n",L"hoy",L"tarde",L"pronto",L"todav�a",L"ayer",L"reci�n",L"nunca",
	L"diferente",L"falso",L"fat	",L"d�bil",L"llano",L"est�pido",L"libre",L"lleno",L"generoso",L"bueno",
	L"siempre",L"jam�s",L"ahora",L"ah�",L"all�",L"aqu�",L"ac�",L"delante",L"detr�s",L"arriba",L"abajo",
	L"pobre",L"r�pido",L"tranquilo",L"rico",L"derecha",L"correcto",L"�spero",L"seguro",L"serio",L"corto",
	L"similar",L"muy",L"m�s",L"poco",L"bastante",L"menos",L"casi",L"talvez",L"acaso",L"quiz�s",L"tampoco",
	L"estupendo",L"atractivo",L"feliz",L"saludable",L"hueco",L"enorme",L"hambriento",L"izquierda",L"ligero",L"est�",
	L"largo",L"ruidoso",L"bonito",L"taca�o",L"cerca",L"necesario",L"viejo",L"abierto",L"contrario",L"paralelo", L"o",
	L"dormido",L"despierto",L"malo",L"precioso",L"agrio",L"brillante",L"barato",L"limpio",L"claro",L"cruel",L"profundo",
	L"simple",L"fino",L"suave",L"s�lido",L"especial",L"picante",L"pegajoso",L"directo",L"extra�o",L"repentino",L"dulce",
	L"aburrido",L"�cido",L"alegre",L"alto",L"amargo",L"ancho",L"atrevido",L"azul",L"bajo",L"blanco",L"blando",L"brando",
	L"bonito",L"buen",L"bueno",L"caliente",L"capaz",L"central",L"chungo",L"mal",L"com�n",L"conocido",L"contento",L"corto",L"s�",
	L"d�bil",L"derecho",L"diferente",L"dif�cil",L"divertido",L"dulce",L"duro",L"enfermo",L"estrecho",L"exterior",L"f�cil", L"y",
	L"imposible",L"interesante",L"interior",L"in�til",L"izquierdo",L"joven",L"largo", L"lento",L"listo",L"masivo", L"mayor",L"no",
	L"mejor",L"menor",L"mucho",L"muerto",L"musical",L"nacional",L"natural",L"negro",L"nuevo",L"peor",L"peque�o",L"perfecto",L"qu�",L"si",
	L"falso",L"famoso",L"feo",L"final",L"fresco",L"fr�o",L"fuerte",L"gordo",L"gran",L"grande",L"guapo",L"guay",L"h�medo",L"igual",L"que",
	L"sano", L"seco",L"segundo",L"simple",L"sinverg�enza",L"social",L"solo",L"soso",L"t�mido",L"tonto",L"triste",L"�til",L"jov�n",L"c�mo"
	L"pobre",L"pouco",L"popular",L"posible",L"primer",L"primero",L"principal",L"pr�ximo",L"raro",L"real",L"recto",L"rico",L"rojo",L"como"
	});

const std::unordered_set <std::wstring> filtroTerminaciones
({
	L"ar",
	L"ir",
	L"er",
	L"so",
	L"to",
	L"t�",
	L"cho",
	L"ado",
	L"ido",
	L"aba",
	L"ida",
	L"ara",
	L"idas",
	L"idos",
	L"aron",
	L"ar�n",
	L"eron",
	L"ando",
	L"ados",
	L"ci�n",
	L"imos",
	L"irse",
	L"emos",
	L"aban",
	L"iendo"
	L"mente"
	
	});

// Terminaciones
#endif 