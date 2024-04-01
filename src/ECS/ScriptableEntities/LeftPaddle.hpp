#pragma once
#include <string>
#include <vector>
#include <Canis/ScriptableEntity.hpp>
#include <Canis/ECS/Components/RectTransformComponent.hpp>

class LeftPaddle : public Canis::ScriptableEntity
{
private:
    glm::vec2   m_direction;
    float       m_speed;
    
public:
    void OnCreate()
    {
        Canis::Log("Left Paddle Loaded");
    }

    void OnReady()
    {
       
    }
    
    void OnDestroy()
    {

    }

    void OnUpdate(float _dt)
    {
        auto& rect = GetComponent<Canis::RectTransformComponent>();
        
        float halfSizeX = rect.size.x/2.0f;
        float halfSizeY = rect.size.y/2.0f;

        if(GetInputManager().GetKey(SDL_SCANCODE_W))
        {
            if(!(rect.position.y + halfSizeY >= GetWindow().GetScreenHeight()/2.0f)){
                m_direction = glm::vec2(0.0f, 1.0f);
                m_speed = 300.0f;
            }
            else{
                m_direction = glm::vec2(0.0f, 0.0f);
                m_speed = 0;
            }
        }
        else if(GetInputManager().GetKey(SDL_SCANCODE_S))
        {
            if(!(rect.position.y - halfSizeY <= GetWindow().GetScreenHeight()/-2.0f)){
                m_direction = glm::vec2(0.0f, -1.0f);
                m_speed = 300.0f;
            }
            else{
                m_direction = glm::vec2(0.0f, 0.0f);
                m_speed = 0;
            }
        }
        else
        {
            m_direction = glm::vec2(0.0f, 0.0f);
            m_speed = 0;
        }

        rect.position += (m_direction * (m_speed * _dt));
    }
};

bool DecodeLeftPaddle(const std::string &_name, Canis::Entity &_entity)
{
    if (_name == "LeftPaddle")
    {
        Canis::ScriptComponent scriptComponent = {};
        scriptComponent.Bind<LeftPaddle>();
        _entity.AddComponent<Canis::ScriptComponent>(scriptComponent);
        return true;
    }
    return false;
}
