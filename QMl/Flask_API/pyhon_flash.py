from flask import Flask, request, jsonify
from flask_cors import CORS
app = Flask(__name__)
CORS(app)

stored_data = None

@app.route('/test', methods=['GET', 'POST', 'OPTIONS'])
def test():
    global stored_data
    if request.method == 'POST':
        data = request.get_json()
        stored_data = data
        print("Received data:", data)
        print("POST")
        response = {
            'message': 'Data received successfully',
            'data': data
        }
        return jsonify(response), 200
    elif request.method == 'OPTIONS':
        response = app.make_default_options_response()
        return response
    elif request.method == 'GET':
        print("GET")
        if stored_data is not None:
            return jsonify(stored_data), 200
        else:
            return jsonify({"message": "No data stored"}), 404

if __name__ == '__main__':
    app.run(debug=True)

