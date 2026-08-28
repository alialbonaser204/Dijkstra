#pragma once
#include "Step.hpp"

/**
 * @class CarStep
 * @brief De CarStep klasse vertegenwoordigt een stap of verbinding per auto tussen twee stations.
 */
class CarStep : public Step {
public:
    /**
     * @brief Constructor voor het initialiseren van een auto stap met een startstation, eindstation en gewicht.
     * @param from Pointer naar het startstation.
     * @param to Pointer naar het eindstation.
     * @param weight Het gewicht van de stap (bijvoorbeeld afstand of tijd).
     */

    CarStep(Station* from, Station* to, float weight);
    /**
     * @brief Methode om het type vervoer te verkrijgen (in dit geval 'Car').
     * @return Een string die het type vervoer vertegenwoordigt.
     */

    std::string getTransportType() const override;
};
