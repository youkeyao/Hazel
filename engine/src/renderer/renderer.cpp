#include "renderer/renderer.h"
#include "renderer/renderer_command.h"
#include "platform/opengl/opengl_shader.h"

namespace hazel {

    Renderer::SceneData* Renderer::m_scene_data = new Renderer::SceneData();

    void Renderer::init()
    {
        RendererCommand::init();
    }

    void Renderer::begin_scene(OrthographicCamera& camera)
    {
        m_scene_data->view_projection_matrix = camera.get_view_projection_matrix();
    }

    void Renderer::end_scene()
    {

    }

    void Renderer::submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertex_array, const glm::mat4& transform)
    {
        shader->bind();
        shader->set_mat4("u_view_projection", m_scene_data->view_projection_matrix);
        shader->set_mat4("u_transform", transform);

        vertex_array->bind();
        RendererCommand::draw_indexed(vertex_array);
    }

}