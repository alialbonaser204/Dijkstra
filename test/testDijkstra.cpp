#include "include/catch.hpp"
#include "../source/include/Station.hpp"
#include "../source/include/CarStep.hpp"
#include "../source/include/Graph.hpp"


TEST_CASE("Dijkstra's algoritme berekent de kortste afstanden correct", "[dijkstra]") {
    // Maak stations aan
    Station* stationA = new Station("Station A");
    Station* stationB = new Station("Station B");
    Station* stationC = new Station("Station C");

    // Maak stappen aan
    Step* carStep1 = new CarStep(stationA, stationB, 4);
    Step* carStep2 = new CarStep(stationA, stationC, 2);
    Step* carStep3 = new CarStep(stationC, stationB, 1);

    // Voeg stappen toe aan stations
    stationA->addStep(carStep1);
    stationA->addStep(carStep2);
    stationC->addStep(carStep3);

    // Maak een graph aan
    std::vector<Station*> stations = {stationA, stationB, stationC};
    std::vector<Step*> steps = {carStep1, carStep2, carStep3};
    Graph graph(stations, steps);

    // Test Dijkstra's algoritme vanaf stationA
    auto result = graph.dijkstra(stationA);
    std::unordered_map<Station*, float> afstanden = result.first;

    REQUIRE(afstanden[stationA] == 0);
    REQUIRE(afstanden[stationB] == 3);
    REQUIRE(afstanden[stationC] == 2);

    // Opschonen van dynamisch geheugen
    delete carStep1;
    delete carStep2;
    delete carStep3;
    delete stationA;
    delete stationB;
    delete stationC;
}

