#pragma once
#include "Step.hpp"

// De PlaneStep klasse vertegenwoordigt een stap of verbinding per vliegtuig tussen twee stations
class PlaneStep : public Step {
public:
    // Constructor voor het initialiseren van een vliegtuig stap met een startstation, eindstation en gewicht
    PlaneStep(Station* from, Station* to, float weight);

    // Methode om het type vervoer te verkrijgen (in dit geval 'Plane')
    std::string getTransportType() const override;
};