// LICENSE HERE.

//
// client/rmlui/interfaces/RenderInterface.h
//
//
// RmlUI N&C Render Interface implementation.
//
#ifndef __CLIENT_RMLUI_INTERFACES_RENDERINTERFACE_H__
#define __CLIENT_RMLUI_INTERFACES_RENDERINTERFACE_H__

 /**
	N&C Quake RML Render Interface.
  */

class RmlUiRenderInterface : public Rml::RenderInterface
{
public:
	RmlUiRenderInterface();

	// Called when the render viewport size has changed.
	void SetViewportArea(int width, int height);

	// Called to initialize the renderer, enable certain OpenGL states.
	void Initialize();

	/// Called by RmlUi when it wants to render geometry that it does not wish to optimise.
	void RenderGeometry(Rml::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rml::TextureHandle texture, const Rml::Vector2f& translation) override;

	/// Called by RmlUi when it wants to compile geometry it believes will be static for the forseeable future.
	Rml::CompiledGeometryHandle CompileGeometry(Rml::Vertex* vertices, int num_vertices, int* indices, int num_indices, Rml::TextureHandle texture) override;

	/// Called by RmlUi when it wants to render application-compiled geometry.
	void RenderCompiledGeometry(Rml::CompiledGeometryHandle geometry, const Rml::Vector2f& translation) override;
	/// Called by RmlUi when it wants to release application-compiled geometry.
	void ReleaseCompiledGeometry(Rml::CompiledGeometryHandle geometry) override;

	/// Called by RmlUi when it wants to enable or disable scissoring to clip content.
	void EnableScissorRegion(bool enable) override;
	/// Called by RmlUi when it wants to change the scissor region.
	void SetScissorRegion(int x, int y, int width, int height) override;

	/// Called by RmlUi when a texture is required by the library.
	bool LoadTexture(Rml::TextureHandle& texture_handle, Rml::Vector2i& texture_dimensions, const Rml::String& source) override;
	/// Called by RmlUi when a texture is required to be built from an internally-generated sequence of pixels.
	bool GenerateTexture(Rml::TextureHandle& texture_handle, const Rml::byte* source, const Rml::Vector2i& source_dimensions) override;
	/// Called by RmlUi when a loaded texture is no longer required.
	void ReleaseTexture(Rml::TextureHandle texture_handle) override;

	/// Called by RmlUi when it wants to set the current transform matrix to a new matrix.
	void SetTransform(const Rml::Matrix4f* transform) override;

	// Extensions used by the test suite
	struct Image {
		int width = 0;
		int height = 0;
		int num_components = 0;
		Rml::UniquePtr<Rml::byte[]> data;
	};
	Image CaptureScreen();

protected:
	int m_width;
	int m_height;
	bool m_transform_enabled;
};

#endif // __CLIENT_RMLUI_INTERFACES_SHELLSYSTEMINTERFACE_H__
