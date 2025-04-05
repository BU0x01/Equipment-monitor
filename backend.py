from flask import Flask, request, jsonify

app = Flask(__name__)

# Store the equipment data
equipment_data = []

@app.route('/track', methods=['POST'])
def track_equipment():
    data = request.get_json()
    
    # Store the data
    equipment_data.append(data)
    
    # Optionally, process or store in a database
    print(f"Received data: {data}")
    
    return jsonify({"status": "success"}), 200

@app.route('/get_data', methods=['GET'])
def get_data():
    return jsonify(equipment_data)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
