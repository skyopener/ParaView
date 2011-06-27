/*=========================================================================

  Program:   ParaView
  Module:    vtkPVImplicitPlaneRepresentation.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkPVImplicitPlaneRepresentation - extends vtkImplicitPlaneRepresentation
// .SECTION Description
// vtkPVImplicitPlaneRepresentation extends vtkImplicitPlaneRepresentation to
// add ParaView proper initialisation values

#ifndef __vtkPVImplicitPlaneRepresentation_h
#define __vtkPVImplicitPlaneRepresentation_h

#include "vtkImplicitPlaneRepresentation.h"

class vtkTransform;
class VTK_EXPORT vtkPVImplicitPlaneRepresentation : public vtkImplicitPlaneRepresentation
{
public:
  static vtkPVImplicitPlaneRepresentation* New();
  vtkTypeMacro(vtkPVImplicitPlaneRepresentation, vtkImplicitPlaneRepresentation);
  void PrintSelf(ostream& os, vtkIndent indent);

  void SetTransformedOrigin(double x, double y, double z);
  double* GetTransformedOrigin();

  void SetTransformedNormal(double x, double y, double z);
  double* GetTransformedNormal();
  
  void PlaceTransformedWidget(double bounds[6]);

  //Set the transform that this plane rep is going to be scaled by
  void SetTransform(vtkTransform *transform);
  void ClearTransform();
  
//BTX
protected:
  vtkPVImplicitPlaneRepresentation();
  ~vtkPVImplicitPlaneRepresentation();

  vtkTransform* Transform;
  vtkTransform* InverseTransform;

  bool StoreOriginalInfo;
  double OriginalBounds[6];
  double OriginalOrigin[3];

  double ScaledOrigin[3];
  double ScaledNormal[3];
private:
  vtkPVImplicitPlaneRepresentation(const vtkPVImplicitPlaneRepresentation&); // Not implemented
  void operator=(const vtkPVImplicitPlaneRepresentation&); // Not implemented
//ETX
};

#endif
