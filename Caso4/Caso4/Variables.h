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
	L"por",L"seg�n",L"sin",L"so",L"sobre",L"tras",L"versus",
	L"v�amucho",L"muchos",L"mucha",L"muchas",L"poco",L"pocos",
	L"poca",L"pocas",L"tanto",L"tantos",L"tanta",L"tantas",
	L"bastante",L"bastantes",L"demasiado",L"demasiados",L"demasiada",
	L"demasiadas",L"alguno",L"algunos",L"alguna",L"algunas",L"ninguno",
	L"ninguna",L"algo",L"nada",L"qu�",L"qui�n",L"qui�nes",L"cu�l",L"cu�les",
	L"cu�nto",L"cu�ntos",L"cu�nta",L"cu�ntas",L"d�nde",L"c�mo",L"cuyo",L"cuyos",
	L"cuyas",L"cuya",L"donde",L"quien",L"quienes",L"este",L"ese",L"aqu�l",L"esta",
	L"esa",L"aquella",L"estos",L"esos",L"aquellos",L"estas",L"esas",L"aquellas",L"esto",
	L"eso",L"aquello",L"mi",L"mis",L"m�o",L"m�a",L"m�osm�as",L"tu",L"tus",L"tuyo",L"tuya",
	L"tuyos",L"tuyas",L"su",L"sus",L"suyo",L"suya",L"suyos",L"suyas",L"nuestro",L"nuestra",
	L"nuestros",L"nuestras",L"vuestro",L"vuestra",L"vuestros",L"vuestras",L"yo",L"t�",L"�l",
	L"usted",L"ustedes",L"nosotros",L"nosotras",L"vosotros",L"vosotras",L"ellos",L"ellas",L"me",
	L"te",L"nos",L"se",L"ya",L"a�n",L"hoy",L"tarde",L"pronto",L"todav�a",L"ayer",L"reci�n",L"nunca",
	L"siempre",L"jam�s",L"ahora",L"ah�",L"all�",L"aqu�",L"ac�",L"delante",L"detr�s",L"arriba",L"abajo",
	L"cerca",L"lejos",L"encima",L"fuera",L"mal",L"bien",L"regular",L"despacio",L"as�",L"mejor",L"peor",
	L"similar",L"muy",L"m�s",L"poco",L"bastante",L"demasiado",L"menos",L"mucho",L"algo",L"casi",L"talvez",
	L"acaso",L"quiz�s",L"tampoco",L"probablemente",L"seguramente",L"d�nde",L"cu�ndo",L"qu�",L"cu�n",L"ojal�",L"cu�nto",L"cu�nta"
	
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
	L"ando",
	L"ados",
	L"ci�n",
	L"imos",
	L"emos",
	L"iendo"
	
	});

// Terminaciones
#endif 