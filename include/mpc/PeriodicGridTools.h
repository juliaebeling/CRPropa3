#ifndef MPC_PERIODICGRIDTOOLS_H_
#define MPC_PERIODICGRIDTOOLS_H_

#include "mpc/PeriodicGrid.h"
#include <string>

namespace mpc {

/** Calculate the mean field strength */
Vector3f meanFieldStrength(ref_ptr<VectorGrid> m);

/** Calculate the RMS field strength */
double rmsFieldStrength(ref_ptr<VectorGrid> m);

/** Multiply a magnetic field grid by a factor. */
void scale(ref_ptr<VectorGrid> m, double a);

#ifdef MPC_HAVE_FFTW3F
/**
 Create a random initialization of a turbulent field.
 @param lMin	Minimum wavelength of the turbulence
 @param lMax	Maximum wavelength of the turbulence
 @param index	Power spectral index of the turbulence (-11/3 corresponds to a Kolmogorov spectrum)
 @param Brms	RMS field strength
 @param seed	Random seed
 */
void initTurbulence(ref_ptr<VectorGrid> m, double Brms, double lMin,
		double lMax, double index = -11. / 3., int seed = 0);
#endif // MPC_HAVE_FFTW3F

/** Analytically calculate the correlation length of a turbulent field */
double turbulentCorrelationLength(double lMin, double lMax, double spectralIndex = -11. / 3.);

/**
 Dump / load functions for scalar / 3-vector grids and binary / plain text files.
 The grid points are stored from (0, 0, 0) to (Nx, Ny, Nz) with the z-index changing the fastest.
 Vector components are stored per grid point in xyz-order.

 In case of plain-text files the vector components are separated by a blank or tab and grid points are stored one per line.
 Also there can be any number of comment lines at the beginning of the file, started with a #.

 All functions offer a conversion factor that is multiplied to all values.
 */
// Load a VectorGrid from a binary file with single precision.
void load(ref_ptr<VectorGrid> grid, std::string filename, double c = 1);

// Load a ScalarGrid from a binary file with single precision.
void load(ref_ptr<ScalarGrid> grid, std::string filename, double c = 1);

// Dump a VectorGrid to a binary file.
void dump(ref_ptr<VectorGrid> grid, std::string filename, double c = 1);

// Dump a ScalarGrid to a binary file with single precision.
void dump(ref_ptr<ScalarGrid> grid, std::string filename, double c = 1);

// Load a VectorGrid grid from a plain text file.
void loadTxt(ref_ptr<VectorGrid> grid, std::string filename, double c = 1);

// Load a ScalarGrid from a plain text file.
void loadTxt(ref_ptr<ScalarGrid> grid, std::string filename, double c = 1);

// Dump a VectorGrid to a plain text file.
void dumpTxt(ref_ptr<VectorGrid> grid, std::string filename, double c = 1);

// Dump a ScalarGrid to a plain text file.
void dumpTxt(ref_ptr<ScalarGrid> grid, std::string filename, double c = 1);

} // namespace mpc

#endif /* MPC_PERIODICGRIDTOOLS_H_ */