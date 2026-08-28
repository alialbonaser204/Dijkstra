#pragma once
#include <string>
#include "Station.hpp"

// De Step klasse vertegenwoordigt een stap of verbinding tussen twee stations in een grafiek
class Step {
public:

    // Methode om het startstation van de stap te verkrijgen
    virtual Station* getFrom();

    // Methode om het eindstation van de stap te verkrijgen
    virtual Station* getTo();

    // Methode om het gewicht van de stap te verkrijgen
    virtual float getWeight();

    // Pure virtuele methode om het type vervoer te verkrijgen (moet worden geïmplementeerd door afgeleide klassen)
    virtual std::string getTransportType() const = 0;

protected:
    // Constructor voor het initialiseren van een stap met een startstation, eindstation en gewicht
    Step(Station* from, Station* to, float weight);

private:
    Station* from; // Het startstation van de stap
    Station* to;   // Het eindstation van de stap
    float weight;  // Het gewicht van de stap (bijvoorbeeld afstand of tijd)
};
