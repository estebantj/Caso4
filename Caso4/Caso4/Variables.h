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
	L"por",L"según",L"sin",L"so",L"sobre",L"tras",L"versus",
	L"víamucho",L"muchos",L"mucha",L"muchas",L"poco",L"pocos",
	L"poca",L"pocas",L"tanto",L"tantos",L"tanta",L"tantas",
	L"bastante",L"bastantes",L"demasiado",L"demasiados",L"demasiada",
	L"demasiadas",L"alguno",L"algunos",L"alguna",L"algunas",L"ninguno",
	L"ninguna",L"algo",L"nada",L"qué",L"quién",L"quiénes",L"cuál",L"cuáles",
	L"cuánto",L"cuántos",L"cuánta",L"cuántas",L"dónde",L"cómo",L"cuyo",L"cuyos",
	L"cuyas",L"cuya",L"donde",L"quien",L"quienes",L"este",L"ese",L"aquél",L"esta",
	L"esa",L"aquella",L"estos",L"esos",L"aquellos",L"estas",L"esas",L"aquellas",L"esto",
	L"eso",L"aquello",L"mi",L"mis",L"mío",L"mía",L"míosmías",L"tu",L"tus",L"tuyo",L"tuya",
	L"tuyos",L"tuyas",L"su",L"sus",L"suyo",L"suya",L"suyos",L"suyas",L"nuestro",L"nuestra",
	L"nuestros",L"nuestras",L"vuestro",L"vuestra",L"vuestros",L"vuestras",L"yo",L"tú",L"él",
	L"usted",L"ustedes",L"nosotros",L"nosotras",L"vosotros",L"vosotras",L"ellos",L"ellas",L"me",
	L"te",L"nos",L"se",L"ya",L"aún",L"hoy",L"tarde",L"pronto",L"todavía",L"ayer",L"recién",L"nunca",
	L"siempre",L"jamás",L"ahora",L"ahí",L"allí",L"aquí",L"acá",L"delante",L"detrás",L"arriba",L"abajo",
	L"cerca",L"lejos",L"encima",L"fuera",L"mal",L"bien",L"regular",L"despacio",L"así",L"mejor",L"peor",
	L"similar",L"muy",L"más",L"poco",L"bastante",L"demasiado",L"menos",L"mucho",L"algo",L"casi",L"talvez",
	L"acaso",L"quizás",L"tampoco",L"probablemente",L"seguramente",L"dónde",L"cuándo",L"qué",L"cuán",L"ojalá",L"cuánto",L"cuánta"
	
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
	L"ando",
	L"ados",
	L"ción",
	L"imos",
	L"emos",
	L"iendo"
	
	});

// Terminaciones
#endif 