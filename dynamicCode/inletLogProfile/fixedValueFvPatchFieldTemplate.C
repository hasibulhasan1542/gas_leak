/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2019-2021 OpenCFD Ltd.
    Copyright (C) YEAR AUTHOR, AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "fixedValueFvPatchFieldTemplate.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "unitConversion.H"
#include "PatchFunction1.H"

//{{{ begin codeInclude

//}}} end codeInclude


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

// dynamicCode:
// SHA1 = 70b7ddbf8e8e5427059ff52c06e12618bcb06ee9
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void inletLogProfile_70b7ddbf8e8e5427059ff52c06e12618bcb06ee9(bool load)
{
    if (load)
    {
        // Code that can be explicitly executed after loading
    }
    else
    {
        // Code that can be explicitly executed before unloading
    }
}

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

makeRemovablePatchTypeField
(
    fvPatchVectorField,
    inletLogProfileFixedValueFvPatchVectorField
);

} // End namespace Foam


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::
inletLogProfileFixedValueFvPatchVectorField::
inletLogProfileFixedValueFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF
)
:
    parent_bctype(p, iF)
{
    if (false)
    {
        printMessage("Construct inletLogProfile : patch/DimensionedField");
    }
}


Foam::
inletLogProfileFixedValueFvPatchVectorField::
inletLogProfileFixedValueFvPatchVectorField
(
    const inletLogProfileFixedValueFvPatchVectorField& rhs,
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    parent_bctype(rhs, p, iF, mapper)
{
    if (false)
    {
        printMessage("Construct inletLogProfile : patch/DimensionedField/mapper");
    }
}


Foam::
inletLogProfileFixedValueFvPatchVectorField::
inletLogProfileFixedValueFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const dictionary& dict
)
:
    parent_bctype(p, iF, dict)
{
    if (false)
    {
        printMessage("Construct inletLogProfile : patch/dictionary");
    }
}


Foam::
inletLogProfileFixedValueFvPatchVectorField::
inletLogProfileFixedValueFvPatchVectorField
(
    const inletLogProfileFixedValueFvPatchVectorField& rhs
)
:
    parent_bctype(rhs),
    dictionaryContent(rhs)
{
    if (false)
    {
        printMessage("Copy construct inletLogProfile");
    }
}


Foam::
inletLogProfileFixedValueFvPatchVectorField::
inletLogProfileFixedValueFvPatchVectorField
(
    const inletLogProfileFixedValueFvPatchVectorField& rhs,
    const DimensionedField<vector, volMesh>& iF
)
:
    parent_bctype(rhs, iF)
{
    if (false)
    {
        printMessage("Construct inletLogProfile : copy/DimensionedField");
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::
inletLogProfileFixedValueFvPatchVectorField::
~inletLogProfileFixedValueFvPatchVectorField()
{
    if (false)
    {
        printMessage("Destroy inletLogProfile");
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void
Foam::
inletLogProfileFixedValueFvPatchVectorField::updateCoeffs()
{
    if (this->updated())
    {
        return;
    }

    if (false)
    {
        printMessage("updateCoeffs inletLogProfile");
    }

//{{{ begin code
    #line 39 "/mnt/primary/Thesis/OPENFOAM_CASES/base_3D/0/U/boundaryField/inlet"
const fvPatch& boundaryPatch = patch();
            vectorField& field = *this;

            scalar uStar = 1.368;   // Friction velocity 
            scalar kappa = 0.41;    // von Karman constant
            scalar y0 = 0.1;        // Roughness length
            scalar d = 0.0;         // Zero-plane displacement, use 0.0 if flat-terrain

            const vectorField& Cf = boundaryPatch.Cf();

            forAll(field, faceI)
            {
                scalar y = Cf[faceI].y();
                scalar effectiveY = max(y - d, 0.01); // avoid log(0)

                scalar Uprofile = uStar / kappa * log(effectiveY / y0);

                field[faceI] = vector(Uprofile, 0, 0);
            }
//}}} end code

    this->parent_bctype::updateCoeffs();
}


// ************************************************************************* //

