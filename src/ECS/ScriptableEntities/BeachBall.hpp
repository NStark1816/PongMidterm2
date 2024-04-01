#pragma once
#include <string>
#include <vector>
#include <Canis/ScriptableEntity.hpp>
#include <Canis/ECS/Components/RectTransformComponent.hpp>
#include <Canis/ECS/Components/TextComponent.hpp>

class BeachBall : public Canis::ScriptableEntity
{
private:
    glm::vec2   m_direction;
    float       m_speed;
    float       m_timeBetweenAnimation = 3.0f;
    float       m_countDown = 0.0f;
    unsigned int m_animIndex = 0;
    std::vector<glm::vec2> m_spawnPoints = {};
public:
    unsigned int leftScore = 0;
    unsigned int rightScore = 0;
    void OnCreate()
    {
        m_countDown = m_timeBetweenAnimation;
    }

    void OnReady()
    {
        m_direction = glm::vec2(1.0f, 0.4f);
        m_speed = 150.0f;
    }
    
    void OnDestroy()
    {

    }

    void OnUpdate(float _dt)
    {
        using namespace Canis;
        Canis::Entity leftPaddle = entity.GetEntityWithTag("LEFTPADDLE");
        Canis::Entity rightPaddle = entity.GetEntityWithTag("RIGHTPADDLE");
        Canis::Entity scoreDisplay = entity.GetEntityWithTag("SCORE");
        auto& rectLeftPaddle = leftPaddle.GetComponent<Canis::RectTransformComponent>();
        auto& rectRightPaddle = rightPaddle.GetComponent<Canis::RectTransformComponent>();
        auto& colorLeftPaddle = leftPaddle.GetComponent<Canis::ColorComponent>();
        auto& colorRightPaddle = rightPaddle.GetComponent<Canis::ColorComponent>();
        auto& scoreText = scoreDisplay.GetComponent<Canis::TextComponent>();
        auto& rect = GetComponent<Canis::RectTransformComponent>();
        auto& colorComp = GetComponent<Canis::ColorComponent>();

        Log(std::to_string(rightScore));

        float halfSizeX = rect.size.x/2.0f;
        float halfSizeY = rect.size.y/2.0f;

        if (rect.position.x + halfSizeX >= GetWindow().GetScreenWidth()/2.0f)
        {
            rect.position = vec2(0, 0);
            m_speed = 150.0f;
            rightScore += 1;
            scoreText.text = (std::to_string(leftScore) + " - " + std::to_string(rightScore));
        } 
        else if(rect.position.x - halfSizeX <= GetWindow().GetScreenWidth()/-2.0f)
        {
            rect.position = vec2(0, 0);
            m_speed = 150.0f;
            leftScore += 1;
            scoreText.text = (std::to_string(leftScore) + " - " + std::to_string(rightScore));
        }

        if (rect.position.y + halfSizeY >= GetWindow().GetScreenHeight()/2.0f ||
                rect.position.y - halfSizeY <= GetWindow().GetScreenHeight()/-2.0f)
            m_direction.y *= -1.0f;

        
        rect.position += (m_direction * (m_speed * _dt));

        if (GetInputManager().JustPressedKey(SDLK_p))
            m_speed += 50.0f;
        
        if (GetInputManager().JustPressedKey(SDLK_r))
            m_speed = 150.0f;
        
        if (GetInputManager().JustPressedKey(SDLK_d))
        {
            GetScene().Instantiate("assets/prefebs/test_character.scene");
        }

        colorComp.color = glm::vec4(255.0f / 255, 255.0f / 255, 255.0f / 255, 1.0f);
    }
};

bool DecodeBeachBall(const std::string &_name, Canis::Entity &_entity)
{
    if (_name == "BeachBall")
    {
        Canis::ScriptComponent scriptComponent = {};
        scriptComponent.Bind<BeachBall>();
        _entity.AddComponent<Canis::ScriptComponent>(scriptComponent);
        return true;
    }
    return false;
}