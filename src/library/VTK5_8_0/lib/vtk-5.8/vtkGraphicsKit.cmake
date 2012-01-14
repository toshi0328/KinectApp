# Directory containing class headers.
SET(VTK_GRAPHICS_HEADER_DIR "${VTK_INSTALL_PREFIX}/include/vtk-5.8")

# Classes in vtkGraphics.
SET(VTK_GRAPHICS_CLASSES
  "vtkAnnotationLink"
  "vtkAppendCompositeDataLeaves"
  "vtkAppendFilter"
  "vtkAppendPolyData"
  "vtkAppendSelection"
  "vtkApproximatingSubdivisionFilter"
  "vtkArcSource"
  "vtkAreaContourSpectrumFilter"
  "vtkArrayCalculator"
  "vtkArrowSource"
  "vtkAssignAttribute"
  "vtkAttributeDataToFieldDataFilter"
  "vtkAxes"
  "vtkBandedPolyDataContourFilter"
  "vtkBlankStructuredGrid"
  "vtkBlankStructuredGridWithImage"
  "vtkBlockIdScalars"
  "vtkBoxClipDataSet"
  "vtkBrownianPoints"
  "vtkButterflySubdivisionFilter"
  "vtkButtonSource"
  "vtkCellCenters"
  "vtkCellDataToPointData"
  "vtkCellDerivatives"
  "vtkCellLocatorInterpolatedVelocityField"
  "vtkCellQuality"
  "vtkCleanPolyData"
  "vtkClipClosedSurface"
  "vtkClipConvexPolyData"
  "vtkClipDataSet"
  "vtkClipHyperOctree"
  "vtkClipPolyData"
  "vtkClipVolume"
  "vtkCoincidentPoints"
  "vtkCompositeDataGeometryFilter"
  "vtkCompositeDataProbeFilter"
  "vtkConeSource"
  "vtkConnectivityFilter"
  "vtkContourFilter"
  "vtkContourGrid"
  "vtkConvertSelection"
  "vtkCubeSource"
  "vtkCursor2D"
  "vtkCursor3D"
  "vtkCurvatures"
  "vtkCutter"
  "vtkCylinderSource"
  "vtkDashedStreamLine"
  "vtkDataObjectGenerator"
  "vtkDataObjectToDataSetFilter"
  "vtkDataSetEdgeSubdivisionCriterion"
  "vtkDataSetGradient"
  "vtkDataSetGradientPrecompute"
  "vtkDataSetSurfaceFilter"
  "vtkDataSetToDataObjectFilter"
  "vtkDataSetTriangleFilter"
  "vtkDecimatePolylineFilter"
  "vtkDecimatePro"
  "vtkDelaunay2D"
  "vtkDelaunay3D"
  "vtkDensifyPolyData"
  "vtkDicer"
  "vtkDijkstraGraphGeodesicPath"
  "vtkDijkstraImageGeodesicPath"
  "vtkDiscreteMarchingCubes"
  "vtkDiskSource"
  "vtkEdgePoints"
  "vtkEdgeSubdivisionCriterion"
  "vtkElevationFilter"
  "vtkEllipticalButtonSource"
  "vtkExtractArraysOverTime"
  "vtkExtractBlock"
  "vtkExtractCells"
  "vtkExtractDataOverTime"
  "vtkExtractDataSets"
  "vtkExtractEdges"
  "vtkExtractGeometry"
  "vtkExtractGrid"
  "vtkExtractLevel"
  "vtkExtractPolyDataGeometry"
  "vtkExtractRectilinearGrid"
  "vtkExtractSelectedBlock"
  "vtkExtractSelectedFrustum"
  "vtkExtractSelectedIds"
  "vtkExtractSelectedLocations"
  "vtkExtractSelectedPolyDataIds"
  "vtkExtractSelectedRows"
  "vtkExtractSelectedThresholds"
  "vtkExtractSelectionBase"
  "vtkExtractSelection"
  "vtkExtractTemporalFieldData"
  "vtkExtractTensorComponents"
  "vtkExtractUnstructuredGrid"
  "vtkExtractVectorComponents"
  "vtkFeatureEdges"
  "vtkFieldDataToAttributeDataFilter"
  "vtkFillHolesFilter"
  "vtkFrustumSource"
  "vtkGeodesicPath"
  "vtkGeometryFilter"
  "vtkGlyph2D"
  "vtkGlyph3D"
  "vtkGlyphSource2D"
  "vtkGradientFilter"
  "vtkGraphGeodesicPath"
  "vtkGraphLayoutFilter"
  "vtkGraphToPoints"
  "vtkGraphToPolyData"
  "vtkGridSynchronizedTemplates3D"
  "vtkHedgeHog"
  "vtkHierarchicalDataExtractDataSets"
  "vtkHierarchicalDataExtractLevel"
  "vtkHierarchicalDataLevelFilter"
  "vtkHierarchicalDataSetGeometryFilter"
  "vtkHull"
  "vtkHyperOctreeClipCutPointsGrabber"
  "vtkHyperOctreeContourFilter"
  "vtkHyperOctreeCutter"
  "vtkHyperOctreeDepth"
  "vtkHyperOctreeDualGridContourFilter"
  "vtkHyperOctreeFractalSource"
  "vtkHyperOctreeLimiter"
  "vtkHyperOctreeSampleFunction"
  "vtkHyperOctreeSurfaceFilter"
  "vtkHyperOctreeToUniformGridFilter"
  "vtkHyperStreamline"
  "vtkIconGlyphFilter"
  "vtkIdFilter"
  "vtkImageDataGeometryFilter"
  "vtkImageMarchingCubes"
  "vtkImplicitTextureCoords"
  "vtkInterpolateDataSetAttributes"
  "vtkInterpolatingSubdivisionFilter"
  "vtkKdTreeSelector"
  "vtkLevelIdScalars"
  "vtkLinearExtrusionFilter"
  "vtkLinearSubdivisionFilter"
  "vtkLineSource"
  "vtkLinkEdgels"
  "vtkLoopSubdivisionFilter"
  "vtkMarchingContourFilter"
  "vtkMarchingCubes"
  "vtkMarchingSquares"
  "vtkMaskFields"
  "vtkMaskPoints"
  "vtkMaskPolyData"
  "vtkMassProperties"
  "vtkMatrixMathFilter"
  "vtkMergeCells"
  "vtkMergeDataObjectFilter"
  "vtkMergeFields"
  "vtkMergeFilter"
  "vtkMeshQuality"
  "vtkModelMetadata"
  "vtkModifiedBSPTree"
  "vtkMultiBlockDataGroupFilter"
  "vtkMultiBlockMergeFilter"
  "vtkMultiThreshold"
  "vtkOBBDicer"
  "vtkOBBTree"
  "vtkOutlineCornerFilter"
  "vtkOutlineCornerSource"
  "vtkOutlineFilter"
  "vtkOutlineSource"
  "vtkParametricFunctionSource"
  "vtkPlaneSource"
  "vtkPlatonicSolidSource"
  "vtkPointDataToCellData"
  "vtkPointSource"
  "vtkPolyDataConnectivityFilter"
  "vtkPolyDataNormals"
  "vtkPolyDataPointSampler"
  "vtkPolyDataStreamer"
  "vtkPolyDataToReebGraphFilter"
  "vtkProbeFilter"
  "vtkProbePolyhedron"
  "vtkProbeSelectedLocations"
  "vtkProgrammableAttributeDataFilter"
  "vtkProgrammableDataObjectSource"
  "vtkProgrammableFilter"
  "vtkProgrammableGlyphFilter"
  "vtkProgrammableSource"
  "vtkProjectedTexture"
  "vtkQuadraturePointInterpolator"
  "vtkQuadraturePointsGenerator"
  "vtkQuadratureSchemeDictionaryGenerator"
  "vtkQuadricClustering"
  "vtkQuadricDecimation"
  "vtkQuantizePolyDataPoints"
  "vtkRandomAttributeGenerator"
  "vtkRearrangeFields"
  "vtkRectangularButtonSource"
  "vtkRectilinearGridClip"
  "vtkRectilinearGridGeometryFilter"
  "vtkRectilinearGridToTetrahedra"
  "vtkRectilinearSynchronizedTemplates"
  "vtkRecursiveDividingCubes"
  "vtkReebGraphSimplificationFilter"
  "vtkReebGraphSurfaceSkeletonFilter"
  "vtkReebGraphVolumeSkeletonFilter"
  "vtkReflectionFilter"
  "vtkRegularPolygonSource"
  "vtkReverseSense"
  "vtkRibbonFilter"
  "vtkRotationalExtrusionFilter"
  "vtkRotationFilter"
  "vtkRuledSurfaceFilter"
  "vtkSectorSource"
  "vtkSelectEnclosedPoints"
  "vtkSelectionSource"
  "vtkSelectPolyData"
  "vtkShrinkFilter"
  "vtkShrinkPolyData"
  "vtkSimpleElevationFilter"
  "vtkSliceCubes"
  "vtkSmoothPolyDataFilter"
  "vtkSpatialRepresentationFilter"
  "vtkSpherePuzzleArrows"
  "vtkSpherePuzzle"
  "vtkSphereSource"
  "vtkSplineFilter"
  "vtkSplitField"
  "vtkStreamer"
  "vtkStreamingTessellator"
  "vtkStreamLine"
  "vtkStreamPoints"
  "vtkStreamTracer"
  "vtkStripper"
  "vtkStructuredGridClip"
  "vtkStructuredGridGeometryFilter"
  "vtkStructuredGridOutlineFilter"
  "vtkStructuredPointsGeometryFilter"
  "vtkSubdivideTetra"
  "vtkSubPixelPositionEdgels"
  "vtkSuperquadricSource"
  "vtkSynchronizedTemplates2D"
  "vtkSynchronizedTemplates3D"
  "vtkSynchronizedTemplatesCutter3D"
  "vtkTableBasedClipDataSet"
  "vtkTableToPolyData"
  "vtkTableToStructuredGrid"
  "vtkTemporalPathLineFilter"
  "vtkTemporalStatistics"
  "vtkTensorGlyph"
  "vtkTessellatorFilter"
  "vtkTessellatedBoxSource"
  "vtkTextSource"
  "vtkTexturedSphereSource"
  "vtkTextureMapToCylinder"
  "vtkTextureMapToPlane"
  "vtkTextureMapToSphere"
  "vtkThreshold"
  "vtkThresholdPoints"
  "vtkThresholdTextureCoords"
  "vtkTimeSourceExample"
  "vtkTransformCoordinateSystems"
  "vtkTransformFilter"
  "vtkTransformPolyDataFilter"
  "vtkTransformTextureCoords"
  "vtkTriangleFilter"
  "vtkTriangularTCoords"
  "vtkTubeFilter"
  "vtkUncertaintyTubeFilter"
  "vtkUnstructuredGridGeometryFilter"
  "vtkUnstructuredGridToReebGraphFilter"
  "vtkVectorDot"
  "vtkVectorNorm"
  "vtkVertexGlyphFilter"
  "vtkVolumeContourSpectrumFilter"
  "vtkVoxelContoursToSurfaceFilter"
  "vtkWarpLens"
  "vtkWarpScalar"
  "vtkWarpTo"
  "vtkWarpVector"
  "vtkWindowedSincPolyDataFilter"
  "vtkYoungsMaterialInterface")

# Abstract classes in vtkGraphics.
SET(VTK_GRAPHICS_CLASSES_ABSTRACT
  "vtkApproximatingSubdivisionFilter"
  "vtkButtonSource"
  "vtkDicer"
  "vtkEdgeSubdivisionCriterion"
  "vtkExtractSelectionBase"
  "vtkGeodesicPath"
  "vtkGraphGeodesicPath"
  "vtkInterpolatingSubdivisionFilter"
  "vtkStreamer")

# Wrap-exclude classes in vtkGraphics.
SET(VTK_GRAPHICS_CLASSES_WRAP_EXCLUDE)

# Wrap-special classes in vtkGraphics.
SET(VTK_GRAPHICS_CLASSES_WRAP_SPECIAL)

# Wrappable non-class headers for vtkGraphics.
SET(VTK_GRAPHICS_WRAP_HEADERS)

# Set convenient variables to test each class.
FOREACH(class ${VTK_GRAPHICS_CLASSES})
  SET(VTK_CLASS_EXISTS_${class} 1)
ENDFOREACH(class)
FOREACH(class ${VTK_GRAPHICS_CLASSES_ABSTRACT})
  SET(VTK_CLASS_ABSTRACT_${class} 1)
ENDFOREACH(class)
FOREACH(class ${VTK_GRAPHICS_CLASSES_WRAP_EXCLUDE})
  SET(VTK_CLASS_WRAP_EXCLUDE_${class} 1)
ENDFOREACH(class)
FOREACH(class ${VTK_GRAPHICS_CLASSES_WRAP_SPECIAL})
  SET(VTK_CLASS_WRAP_SPECIAL_${class} 1)
ENDFOREACH(class)
