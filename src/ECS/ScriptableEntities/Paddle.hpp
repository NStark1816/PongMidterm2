#pragma once
#include <string>
#include <vector>
#include <Canis/ScriptableEntity.hpp>
#include <Canis/ECS/Components/RectTransformComponent.hpp>

class Paddle : public Canis::ScriptableEntity
{
private:
    glm::vec2   m_direction;
    float       m_speed;
    
public:
    void OnCreate()
    {
        Canis::Log("Paddle Loaded");
    }

    void OnReady()
    {
       
    }
    
    void OnDestroy()
    {

    }

    void OnUpdate(float _dt)
    {
        if(GetInputManager().GetKey(SDL_SCANCODE_W))
        {
            Canis::Log("DOWN");
            m_direction = glm::vec2(0.0f, 1.0f);
            m_speed = 150.0f;
        }
        else
        {
            m_direction = glm::vec2(0.0f, 0.0f);
            m_speed = 0;
        }

        rect.position += (m_direction * (m_speed * _dt));
    }
};

bool DecodePaddle(const std::string &_name, Canis::Entity &_entity)
{
    if (_name == "Paddle")
    {
        Canis::ScriptComponent scriptComponent = {};
        scriptComponent.Bind<Paddle>();
        _entity.AddComponent<Canis::ScriptComponent>(scriptComponent);
        return true;
    }
    return false;
}
