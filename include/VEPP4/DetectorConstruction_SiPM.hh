#ifndef DetectorConstruction_h
#define DetectorConstruction_h

#include <globals.hh>
#include <G4ThreeVector.hh>
#include <G4VUserDetectorConstruction.hh>
#include "CathodeSD.hh"
#include "ScintillatorSD.hh"


class G4Box;
class G4Tubs;
class G4Cons;
class G4Trd;
class G4Ellipsoid;
class G4SubtractionSolid;
class G4UnionSolid;
class G4BooleanSolid;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
class G4VPVParameterisation;
class G4UserLimits;
class Messenger;
class G4OpticalSurface;

#include <CLHEP\Units\SystemOfUnits.h>
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
     DetectorConstruction();
    ~DetectorConstruction();

  public:
  
     G4VPhysicalVolume* Construct();
     void setDefaultDimensions();
	 G4VSensitiveDetector* GetSensetiveDetector() { return theCathodeSD; }
	 G4VPhysicalVolume*    GetScintillator() { return physiScint; }

  private:

     G4Box*             solidWorld;    // pointer to the solid envelope 
     G4LogicalVolume*   logicWorld;    // pointer to the logical envelope
     G4VPhysicalVolume* physiWorld;    // pointer to the physical envelope
     
     G4Box*             solidScint;   // pointer to the conic solid Scintillator
     G4LogicalVolume*   logicScint;   // pointer to the logical Scintillator
     G4VPhysicalVolume* physiScint;   // pointer to the physical Scintillator

	 G4Box*             solidEpoxy;
	 G4LogicalVolume*   logicEpoxy;
	 G4VPhysicalVolume* physiEpoxy;
  
     G4Tubs*            solidGrease;
     G4LogicalVolume*   logicGrease;
     G4VPhysicalVolume* physiGrease;

     G4Box*             solidCathode;  // pointer to the solid Cathode
     G4LogicalVolume*   logicCathode;  // pointer to the logical Cathode
     G4VPhysicalVolume* physiCathode;  // pointer to the physical Cathode

	 G4Box*             solidSiBulk;  // 
	 G4LogicalVolume*   logicSiBulk;  // 
	 G4VPhysicalVolume* physiSiBulk;  // 

     // surfaces
     G4OpticalSurface *polishedAir;          // polished crystal surface, not wrapped
     G4OpticalSurface *polishedWhitePainted; // polished crystal surface painted white
	 G4OpticalSurface *groundWhitePainted;   // ground crystal surface painted white
	 G4OpticalSurface *polishedBlackPainted; // polished crystal surface painted black
	 G4OpticalSurface *groundBlackPainted;   // ground crystal surface painted black

     G4OpticalSurface *CathodeMaterial;      // surface between window and cathode

     // arbitraryly valued variables (not changeable by user)
     G4double fWorldLength;            // Full length of the world volume

     // user-changeable variables
     G4double fSourceDistance;

	 G4double fSteelCaseR1;
	 G4double fSteelCaseR2;
	 G4double fSteelCaseLength;

	 G4double fAlCupLength;

	 G4double fScintDimX;
	 G4double fScintDimY;
	 G4double fScintDimZ;

	 G4double fGreaseRadius;
	 G4double fGreaseThickness;

	 G4double fEpoxyDimX;
	 G4double fEpoxyDimY;
	 G4double fEpoxyThickness;

	 G4double fCathodeDimX;
	 G4double fCathodeDimY;
	 G4double fCathodeThickness;

	 //Sensetive detector data
     CathodeSD*      theCathodeSD;
	 ScintillatorSD* theScintillatorSD;

     void defineMaterials();
     void defineSurfaces();
     G4VPhysicalVolume* constructDetector();

     void updateWorldLength();
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
