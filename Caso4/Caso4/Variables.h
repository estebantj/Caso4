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
	L"por",L"según",L"sin",L"e",L"sobre",L"tras",L"versus",
	L"víamucho",L"muchos",L"mucha", L"muchas",L"",L"pocos",
	L"poca",L"pocas",L"tanto",L"tantos",L"tanta",L"tantas",
	L"bastante",L"bastantes",L"demasiada",L"demasiadas",L"alguno",L"sí",
	L"algunos",L"alguna",L"algunas",L"ninguno",	L"ninguna",L"algo",L"es",
	L"nada",L"qué",L"quién",L"quiénes",L"cuál",L"cuáles", L"cuánto",L"fue",
	L"cuántos",L"cuánta",L"cuántas",L"dónde",L"cómo",L"cuyo",L"cuyos",L"surgió",
	L"cuyas",L"cuya",L"donde",L"quien",L"quienes",L"este",L"ese",L"aquél",L"esta",
	L"probablemente",L"seguramente",L"cuándo",L"cuán",L"ojalá",L"cuánto",L"cuánta"
	L"esa",L"aquella",L"estos",L"esos",L"aquellos",L"estas",L"esas",L"aquellas",L"esto",
	L"eso",L"aquello",L"mi",L"mis",L"mío",L"mía",L"míosmías",L"tu",L"tus",L"tuyo",L"tuya",
	L"tuyos",L"tuyas",L"su",L"sus",L"suyo",L"suya",L"suyos",L"suyas",L"nuestro",L"nuestra",
	L"nuestros",L"nuestras",L"vuestro",L"vuestra",L"vuestros",L"vuestras",L"yo",L"tú",L"él",
	L"cerca",L"lejos",L"encima",L"fuera",L"bien",L"regular",L"despacio",L"así",L"mejor",L"peor",
	L"usted",L"ustedes",L"nosotros",L"nosotras",L"vosotros",L"vosotras",L"ellos",L"ellas", L"me",
	L"te",L"nos",L"se",L"ya",L"aún",L"hoy",L"tarde",L"pronto",L"todavía",L"ayer",L"recién",L"nunca",
	L"diferente",L"falso",L"fat	",L"débil",L"llano",L"estúpido",L"libre",L"lleno",L"generoso",L"bueno",
	L"siempre",L"jamás",L"ahora",L"ahí",L"allí",L"aquí",L"acá",L"delante",L"detrás",L"arriba",L"abajo",
	L"pobre",L"rápido",L"tranquilo",L"rico",L"derecha",L"correcto",L"áspero",L"seguro",L"serio",L"corto",
	L"similar",L"muy",L"más",L"poco",L"bastante",L"menos",L"casi",L"talvez",L"acaso",L"quizás",L"tampoco",
	L"estupendo",L"atractivo",L"feliz",L"saludable",L"hueco",L"enorme",L"hambriento",L"izquierda",L"ligero",L"está",
	L"largo",L"ruidoso",L"bonito",L"tacaño",L"cerca",L"necesario",L"viejo",L"abierto",L"contrario",L"paralelo", L"o",
	L"dormido",L"despierto",L"malo",L"precioso",L"agrio",L"brillante",L"barato",L"limpio",L"claro",L"cruel",L"profundo",
	L"simple",L"fino",L"suave",L"sólido",L"especial",L"picante",L"pegajoso",L"directo",L"extraño",L"repentino",L"dulce",
	L"aburrido",L"ácido",L"alegre",L"alto",L"amargo",L"ancho",L"atrevido",L"azul",L"bajo",L"blanco",L"blando",L"brando",
	L"bonito",L"buen",L"bueno",L"caliente",L"capaz",L"central",L"chungo",L"mal",L"común",L"conocido",L"contento",L"corto",L"sí",
	L"débil",L"derecho",L"diferente",L"difícil",L"divertido",L"dulce",L"duro",L"enfermo",L"estrecho",L"exterior",L"fácil", L"y",
	L"imposible",L"interesante",L"interior",L"inútil",L"izquierdo",L"joven",L"largo", L"lento",L"listo",L"masivo", L"mayor",L"no",
	L"mejor",L"menor",L"mucho",L"muerto",L"musical",L"nacional",L"natural",L"negro",L"nuevo",L"peor",L"pequeño",L"perfecto",L"qué",L"si",
	L"falso",L"famoso",L"feo",L"final",L"fresco",L"frío",L"fuerte",L"gordo",L"gran",L"grande",L"guapo",L"guay",L"húmedo",L"igual",L"que",
	L"sano", L"seco",L"segundo",L"simple",L"sinvergüenza",L"social",L"solo",L"soso",L"tímido",L"tonto",L"triste",L"útil",L"jovén",L"cómo"
	L"pobre",L"pouco",L"popular",L"posible",L"primer",L"primero",L"principal",L"próximo",L"raro",L"real",L"recto",L"rico",L"rojo",L"como"
	});

const std::unordered_set <std::wstring> filtroTerminaciones
({
	L"ar",
	L"ir",
	L"er",
	L"so",
	L"to",
	L"tó",
	L"cho",
	L"ado",
	L"ido",
	L"aba",
	L"ida",
	L"ara",
	L"idas",
	L"idos",
	L"aron",
	L"arán",
	L"eron",
	L"ando",
	L"ados",
	L"ción",
	L"imos",
	L"irse",
	L"emos",
	L"aban",
	L"iendo"
	L"mente"
	
	});

// Terminaciones
#endif 