This repository contains a specialized CFD simulation case designed to study the behavior of gas leaks in open-air settings. By leveraging **OpenFOAM**, the project models how gases disperse under various environmental conditions, providing critical insights for safety analysis and environmental risk assessment.

**Key Features:**
*   **OpenFOAM Case Configuration:** A complete simulation setup including:
    *   `0/`: Initial and boundary conditions for parameters like velocity ($U$), pressure ($p$), and species concentration.
    *   `constant/`: Definition of physical properties, transport models, and mesh geometry.
    *   `system/`: Numerical schemes ($fvSchemes$), solver controls ($fvSolution$), and simulation timing ($controlDict$).
*   **Transient Analysis:** Includes time-step directories (e.g., `0`, `1`, `2`, `3`) reflecting the time-dependent nature of gas dispersion.
*   **Dynamic Code Support:** Features a `dynamicCode` directory, suggesting custom boundary conditions or source terms for advanced leak modeling.
*   **Post-Processing Ready:** Includes a `p.foam` file for seamless integration with **ParaView** to visualize plume behavior and concentration gradients.

### **Technical Stack:**
*   **Primary Engine:** OpenFOAM (Open-source Field Operation and Manipulation)
*   **Language:** C++ (Solver logic and dictionary files)
*   **Visualization:** ParaView

### **Use Cases:**
*   **Industrial Safety:** Assessing the "hazard zone" or Lower Explosive Limit (LEL) reach of a gas leak.
*   **Environmental Engineering:** Studying pollutant dispersion in urban or open industrial landscapes.
*   **Research:** Validating numerical models against experimental atmospheric dispersion data.

### **Who Is This For?**
This project is a practical resource for **Safety Engineers**, **CFD Practitioners**, and **Researchers** focused on industrial hazard modeling, environmental fluid mechanics, and atmospheric dispersion.
