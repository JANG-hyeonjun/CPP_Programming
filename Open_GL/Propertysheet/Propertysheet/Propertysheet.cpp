#if 0
#include <iostream>
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
// ----------------------------------------------------------------------------
typedef OpenMesh::PolyMesh_ArrayKernelT<>  MyMesh;
// ----------------------------------------------------------------------------
// Build a simple cube and write it to std::cout

int main()
{
    MyMesh mesh;
    // generate vertices
    MyMesh::VertexHandle vhandle[8];
    vhandle[0] = mesh.add_vertex(MyMesh::Point(-1, -1, 1));
    vhandle[1] = mesh.add_vertex(MyMesh::Point(1, -1, 1));
    vhandle[2] = mesh.add_vertex(MyMesh::Point(1, 1, 1));
    vhandle[3] = mesh.add_vertex(MyMesh::Point(-1, 1, 1));
    vhandle[4] = mesh.add_vertex(MyMesh::Point(-1, -1, -1));
    vhandle[5] = mesh.add_vertex(MyMesh::Point(1, -1, -1));
    vhandle[6] = mesh.add_vertex(MyMesh::Point(1, 1, -1));
    vhandle[7] = mesh.add_vertex(MyMesh::Point(-1, 1, -1));
    // generate (quadrilateral) faces
    std::vector<MyMesh::VertexHandle>  face_vhandles;
    face_vhandles.clear();
    face_vhandles.push_back(vhandle[0]);
    face_vhandles.push_back(vhandle[1]);
    face_vhandles.push_back(vhandle[2]);
    face_vhandles.push_back(vhandle[3]);
    mesh.add_face(face_vhandles);

    face_vhandles.clear();
    face_vhandles.push_back(vhandle[7]);
    face_vhandles.push_back(vhandle[6]);
    face_vhandles.push_back(vhandle[5]);
    face_vhandles.push_back(vhandle[4]);
    mesh.add_face(face_vhandles);
    face_vhandles.clear();
    face_vhandles.push_back(vhandle[1]);
    face_vhandles.push_back(vhandle[0]);
    face_vhandles.push_back(vhandle[4]);
    face_vhandles.push_back(vhandle[5]);
    mesh.add_face(face_vhandles);
    face_vhandles.clear();
    face_vhandles.push_back(vhandle[2]);
    face_vhandles.push_back(vhandle[1]);
    face_vhandles.push_back(vhandle[5]);
    face_vhandles.push_back(vhandle[6]);
    mesh.add_face(face_vhandles);
    face_vhandles.clear();
    face_vhandles.push_back(vhandle[3]);
    face_vhandles.push_back(vhandle[2]);
    face_vhandles.push_back(vhandle[6]);
    face_vhandles.push_back(vhandle[7]);
    mesh.add_face(face_vhandles);
    face_vhandles.clear();
    face_vhandles.push_back(vhandle[0]);
    face_vhandles.push_back(vhandle[3]);
    face_vhandles.push_back(vhandle[7]);
    face_vhandles.push_back(vhandle[4]);
    mesh.add_face(face_vhandles);
    // write mesh to output.obj
    try
    {
        if (!OpenMesh::IO::write_mesh(mesh, "output.off"))
        {
            std::cerr << "Cannot write mesh to file 'output.off'" << std::endl;
            return 1;
        }
    }
    catch (std::exception& x)
    {
        std::cerr << x.what() << std::endl;
        return 1;
    }

    return 0;
}
#endif

#if 1 

#define _CRT_SECURE_NO_WARNINGS

#include "vtkAutoInit.h" 
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);
#include <vtkActor.h>
#include <vtkConeSource.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>


int main(int, char* [])
{
    vtkNew<vtkNamedColors> colors;

    // Create a sphere
    vtkNew<vtkSphereSource> sphereSource;
    sphereSource->SetCenter(2.0, 0.0, 0.0);
    sphereSource->Update();

    // Create a mapper and actor
    vtkNew<vtkPolyDataMapper> sphereMapper;
    sphereMapper->SetInputConnection(sphereSource->GetOutputPort());

    vtkNew<vtkActor> sphereActor;
    sphereActor->SetMapper(sphereMapper.Get());
    sphereActor->GetProperty()->SetColor(
        colors->GetColor3d("MistyRose").GetData());

    // Create a cone
    vtkNew<vtkConeSource> coneSource;

    // Create a mapper and actor
    vtkNew<vtkPolyDataMapper> coneMapper;
    coneMapper->SetInputConnection(coneSource->GetOutputPort());

    vtkNew<vtkActor> coneActor;
    coneActor->SetMapper(coneMapper.Get());
    coneActor->GetProperty()->SetColor(
        colors->GetColor3d("LightGoldenrodYellow").GetData());

    // A renderer and render window
    vtkNew<vtkRenderer> renderer;
    vtkNew<vtkRenderWindow> renderWindow;
    renderWindow->AddRenderer(renderer.Get());
    renderWindow->SetWindowName("TrackballCamera");

    // An interactor
    vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
    renderWindowInteractor->SetRenderWindow(renderWindow.Get());

    // Add the actors to the scene
    renderer->AddActor(sphereActor.Get());
    renderer->AddActor(coneActor.Get());
    renderer->SetBackground(colors->GetColor3d("SlateGray").GetData());

    // Render an image (lights and cameras are created automatically)
    renderWindow->Render();

    vtkNew<vtkInteractorStyleTrackballCamera> style;

    renderWindowInteractor->SetInteractorStyle(style.Get());

    // Begin mouse interaction
    renderWindowInteractor->Start();

    return EXIT_SUCCESS;
}


#endif 


# if 0
#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main()
{
    MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    std::cout << m << std::endl;
}
#endif