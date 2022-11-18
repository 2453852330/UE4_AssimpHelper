// Fill out your copyright notice in the Description page of Project Settings.


#include "AssimpUtils.h"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "assimp/mesh.h"
#include "assimp/vector3.h"

void UAssimpUtils::CFL_Test(FString FileName,TArray<FVector> & Vertex,TArray<int32> & Indices)
{
	Assimp::Importer Importer;
    const aiScene * scene =	Importer.ReadFile(TCHAR_TO_UTF8(*FileName),aiProcess_Triangulate | aiProcess_SortByPType | aiProcess_FixInfacingNormals);
	if (scene)
	{
		uint32 mesh_num = scene->mNumMeshes;
		UE_LOG(LogTemp,Warning,TEXT("[AssimpUtils][find %d mesh ]"),mesh_num);

		if (mesh_num)
		{
			aiMesh * mesh = scene->mMeshes[0];
			if (mesh)
			{
				// vertex
				uint32 vertex_num = mesh->mNumVertices;
				UE_LOG(LogTemp,Warning,TEXT("[AssimpUtils][find %d vertex]"),vertex_num);

				for (uint32 i = 0 ; i < vertex_num; ++i)
				{
					FVector temp_point(mesh->mVertices[i].x,mesh->mVertices[i].y,mesh->mVertices[i].z);
					Vertex.Add(temp_point);
					// UE_LOG(LogTemp,Warning,TEXT("[AssimpUtils][vertex [%d] = {%s}]"),i,*temp_point.ToString());
				}


				uint32 face_num = mesh->mNumFaces;
				UE_LOG(LogTemp,Warning,TEXT("[AssimpUtils][find %d faces]"),face_num);
				for (uint32 i = 0; i < face_num; ++i)
				{
					// UE_LOG(LogTemp,Warning,TEXT("[AssimpUtils][face [%d] has {%d} indices]"),i,mesh->mFaces[i].mNumIndices);
					if ( mesh->mFaces[i].mNumIndices == 3)
					{
						Indices.Add(mesh->mFaces[i].mIndices[0]);
						Indices.Add(mesh->mFaces[i].mIndices[2]);
						Indices.Add(mesh->mFaces[i].mIndices[1]);
					}
				}
			}
		}
	}
}
