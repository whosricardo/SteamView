{% extends "shared/base.html" %}
{% load static %}
{% load socialaccount %}

{% block content %}
<main class="login">
    <div class="container">
        <h2 style="margin-bottom: 24px; font-size: 32px; font-family: 'Special Gothic Expanded One', sans-serif;">LOGIN</h2>
        
        {% if messages %}
            <div class="messages">
                {% for message in messages %}
                    <p class="{{ message.tags }}" style="color: #2c4c9c;">{{ message }}</p>
                {% endfor %}
            </div>
        {% endif %}
        
        <form method="POST">
            {% csrf_token %}
            <div style="text-align: left; margin-bottom: 8px;">
                <label for="username" style="font-size: 14px;">USUÁRIO</label>
            </div>
            <input type="text" id="username" name="username" required autocomplete="username">

            <div style="text-align: left; margin-bottom: 8px;">
                <label for="password" style="font-size: 14px;">SENHA</label>
            </div>
            <input type="password" id="password" name="password" required autocomplete="current-password">

            <button type="submit">ENTRAR</button>

            <div style="margin: 16px 0; text-align: center; color: #666;">
                <span>ou</span>
            </div>

            <a href="{% provider_login_url 'github' %}" class="github-button">
                <img class="img-button" src="{% static 'img/github.svg' %}" alt="GitHub">
                GITHUB
            </a>                                  
        </form>
        <p style="font-size: 14px; margin-top: 24px;">
            Não tem uma conta? 
            <a href="{% url 'cadastro' %}" style="color: #2c4c9c; text-decoration: none; font-weight: bold;">
                Cadastre-se
            </a>
        </p>
    </div>
</main>
{% endblock %}