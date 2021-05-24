#pragma once
#include "resource.h"

class Texture;
class ConstantBuffer;

class Material : public Resource
{
public:
	struct Property
	{
		float4 albedo = {};
		float4 specular = { 0.18f, 0.18f, 0.18f, 0.0f };
		BOOL useAlbedoMap = FALSE;
		BOOL useNormalMap = FALSE;
		BOOL useSpecularMap = FALSE;
		float shininess = 20.0f;
	};

public:
	Material(const aiMaterial& material, const std::string& filePath);

public:
	void Bind() const;

private:
	std::shared_ptr<Texture> pAlbedoMap;
	std::shared_ptr<Texture> pNormalMap;
	std::shared_ptr<Texture> pSpecularMap;

	Property property;
	std::unique_ptr<ConstantBuffer> pConstantBuffer;
};