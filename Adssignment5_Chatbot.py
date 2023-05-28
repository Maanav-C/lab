responses = {
    'hello':"hi i amchat bot assignment.",
    'bye':"thank you for your time.",
    'help':"i am here to help how can i assist you?",
    "samsung":"some of the latest options available are ergnrsigreoigherg",
    "products":"We have a wide range opof products available.",
    "options":"options avilable",
    "shipping":"we have free shipping",
    "returns":"30 days from purchase",
    "default":"i'm sorry i didnt understand that. could you rephrase that?"
}

def chat_bot_responses(user_input):
    user_input = user_input.lower()
    
    if 'hello' in user_input:
        return responses["hello"]
    elif 'help' in user_input:
        return responses["help"]
    elif 'samsung' in user_input:
        return responses["samsung"]
    elif 'products' in user_input:
        return responses["products"]
    elif 'options' in user_input:
        return responses["options"]
    elif 'shipping' in user_input:
        return responses["shipping"]
    elif 'returns' in user_input:
        return responses["returns"]
    elif 'bye' in user_input:
        return responses["bye"]
    else:
        return responses["default"]

print("chatbot: hi, welcome to our onlune store ")

while True:
    user_input = input("User: ")
    response = chat_bot_responses(user_input)
    print("Chatbot: ", response)
    if 'bye' in user_input.lower():
        break