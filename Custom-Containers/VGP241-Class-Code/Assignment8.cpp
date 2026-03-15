#include "Assignment-8.h"
#include "GPS.h"

#include <iostream>

float PrintPath(GPS& gps, const CityA8& fromCity, const CityA8& toCity)
{
	Vector<const CityA8*> pathOutput;
	float dist = gps.FindPath(fromCity, toCity, pathOutput);

	std::cout << fromCity.GetName() << " to " << toCity.GetName() << " Route: ";

	for (std::size_t i = pathOutput.Size() -1; i > 0; --i)
	{
		std::cout << ((*pathOutput[i]).GetName());

		std::cout << " -> ";
	}

	std::cout << toCity.GetName();

	return dist;
}

void FloatToTime(float amount, int& hour, int& min)
{
	int totalMinutes = (int)round(amount * 60);

	hour = totalMinutes / 60;
	min = totalMinutes % 60;
}

void Assignment8()
{
	GPS gpsSystem;

	CityA8 PowelRiver = { "Powel River", { 420, 605 } };
	CityA8 Vancouver = { "Vancouver", { 475, 635 } };
	CityA8 Abbotsford = { "Abbotsford", { 505, 650 } };
	CityA8 Penticton = { "Penticton", { 600, 615 } };
	CityA8 Kelowna = { "Kelowna", { 603, 593 } };
	CityA8 Kamloops = { "Kamloops", { 570, 555 } };
	CityA8 Nelson = { "Nelson", { 685, 608 } };
	CityA8 Creston = { "Creston", { 715, 625 } };
	CityA8 Cranbrook = { "Cranbrook", { 740, 598 } };
	CityA8 Revelstoke = { "Revelstoke", { 642, 526 } };
	CityA8 Lillooet = { "Lillooet", { 512, 556 } };
	CityA8 PrinceGeorge = { "Prince George", { 447, 376 } };
	CityA8 BurnsLake = { "Burns Lake", { 375, 362 } };
	CityA8 Smithers = { "Smithers", { 330, 330 } };
	CityA8 Terrace = { "Terrace", { 285, 345 } };
	CityA8 PrinceRupert = { "Prince Rupert", { 227, 352 } };
	CityA8 DawsonCreek = { "Dawson Creek", { 550, 268 } };
	CityA8 FortStJohn = { "Fort St.John", { 530, 243 } };
	CityA8 FortNelson = { "Fort Nelson", { 470, 102 } };
	CityA8 DeaseLake = { "Dease Lake", { 250, 120 } };
	CityA8 WilliamsLake = { "Williams Lake", { 500, 475 } };
	CityA8 Quesnel = { "Quesnel", { 485, 430 } };

	gpsSystem.AddCity(PowelRiver.GetName(), PowelRiver.GetPosition());
	gpsSystem.AddCity(Vancouver.GetName(), Vancouver.GetPosition());
	gpsSystem.AddCity(Abbotsford.GetName(), Abbotsford.GetPosition());
	gpsSystem.AddCity(Penticton.GetName(), Penticton.GetPosition());
	gpsSystem.AddCity(Kelowna.GetName(), Kelowna.GetPosition());
	gpsSystem.AddCity(Kamloops.GetName(), Kamloops.GetPosition());
	gpsSystem.AddCity(Nelson.GetName(), Nelson.GetPosition());
	gpsSystem.AddCity(Creston.GetName(), Creston.GetPosition());
	gpsSystem.AddCity(Cranbrook.GetName(), Cranbrook.GetPosition());
	gpsSystem.AddCity(Revelstoke.GetName(), Revelstoke.GetPosition());
	gpsSystem.AddCity(Lillooet.GetName(), Lillooet.GetPosition());
	gpsSystem.AddCity(PrinceGeorge.GetName(), PrinceGeorge.GetPosition());
	gpsSystem.AddCity(BurnsLake.GetName(), BurnsLake.GetPosition());
	gpsSystem.AddCity(Smithers.GetName(), Smithers.GetPosition());
	gpsSystem.AddCity(Terrace.GetName(), Terrace.GetPosition());
	gpsSystem.AddCity(PrinceRupert.GetName(), PrinceRupert.GetPosition());
	gpsSystem.AddCity(DawsonCreek.GetName(), DawsonCreek.GetPosition());
	gpsSystem.AddCity(FortStJohn.GetName(), FortStJohn.GetPosition());
	gpsSystem.AddCity(FortNelson.GetName(), FortNelson.GetPosition());
	gpsSystem.AddCity(DeaseLake.GetName(), DeaseLake.GetPosition());
	gpsSystem.AddCity(WilliamsLake.GetName(), WilliamsLake.GetPosition());
	gpsSystem.AddCity(Quesnel.GetName(), Quesnel.GetPosition());

	gpsSystem.ConnectCities(PowelRiver, Vancouver);
	gpsSystem.ConnectCities(Vancouver, Abbotsford);
	gpsSystem.ConnectCities(Abbotsford, Penticton);
	gpsSystem.ConnectCities(Abbotsford, Lillooet);
	gpsSystem.ConnectCities(Penticton, Kelowna);
	gpsSystem.ConnectCities(Penticton, Kamloops);
	gpsSystem.ConnectCities(Kelowna, Nelson);
	gpsSystem.ConnectCities(Nelson, Creston);
	gpsSystem.ConnectCities(Creston, Cranbrook);
	gpsSystem.ConnectCities(Cranbrook, Revelstoke);
	gpsSystem.ConnectCities(Revelstoke, Kamloops);
	gpsSystem.ConnectCities(Kamloops, Lillooet);
	gpsSystem.ConnectCities(Lillooet, WilliamsLake);
	gpsSystem.ConnectCities(WilliamsLake, Quesnel);
	gpsSystem.ConnectCities(Quesnel, PrinceGeorge);
	gpsSystem.ConnectCities(PrinceGeorge, BurnsLake);
	gpsSystem.ConnectCities(BurnsLake, Smithers);
	gpsSystem.ConnectCities(Smithers, Terrace);
	gpsSystem.ConnectCities(Terrace, PrinceRupert);
	gpsSystem.ConnectCities(Terrace, DeaseLake);
	gpsSystem.ConnectCities(DeaseLake, FortNelson);
	gpsSystem.ConnectCities(FortNelson, FortStJohn);
	gpsSystem.ConnectCities(FortStJohn, DawsonCreek);
	gpsSystem.ConnectCities(DawsonCreek, PrinceGeorge);

	Vector<const CityA8*> pathOutputA;
	Vector<const CityA8*> pathOutputB;
	Vector<const CityA8*> pathOutputC;

	float speed = 80; // Km/hr

	CityA8 cityA1 = Vancouver;
	CityA8 cityA2 = Cranbrook;

	CityA8 cityB1 = PrinceRupert;
	CityA8 cityB2 = Kelowna;

	CityA8 cityC1 = FortNelson;
	CityA8 cityC2 = Creston;

	float distA = PrintPath(gpsSystem, cityA1, cityA2);
	std::cout << "\n\n";
	float distB = PrintPath(gpsSystem, cityB1, cityB2);
	std::cout << "\n\n";
	float distC = PrintPath(gpsSystem, cityC1, cityC2);

	std::cout << "\n\n";

	int durationAHr;
	int durationAMin;

	int durationBHr;
	int durationBMin;

	int durationCHr;
	int durationCMin;

	FloatToTime(distA / speed, durationAHr, durationAMin);
	FloatToTime(distB / speed, durationBHr, durationBMin);
	FloatToTime(distC / speed, durationCHr, durationCMin);

	//std::cout << "Distance to Travel:\n";
	//std::cout << "From " << cityA1.GetName() << " to " << cityA2.GetName() << ": " << distA << " km\n";
	//std::cout << "From " << cityB1.GetName() << " to " << cityB2.GetName() << ": " << distB << " km\n";
	//std::cout << "From " << cityC1.GetName() << " to " << cityC2.GetName() << ": " << distC << " km\n";

	std::cout << "Duration to Travel:\n";
	std::cout << "From " << cityA1.GetName() << " to " << cityA2.GetName() << ": " << durationAHr << " hr " << durationAMin << " min\n";
	std::cout << "From " << cityB1.GetName() << " to " << cityB2.GetName() << ": " << durationBHr << " hr " << durationBMin << " min\n";
	std::cout << "From " << cityC1.GetName() << " to " << cityC2.GetName() << ": " << durationCHr << " hr " << durationCMin << " min\n";

	std::cout << "\n\n";
}