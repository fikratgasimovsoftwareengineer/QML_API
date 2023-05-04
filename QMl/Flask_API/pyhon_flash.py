from flask import Flask, request, jsonify

app = Flask(__name__)

stored_data = None

@app.route('/test', methods=['GET', 'POST'])
def test():
    global stored_data
    if request.method == 'POST':
        data = request.get_json()
        stored_data = data
        print("Received data:", data)
        response = {
            'message': 'Data received successfully',
            'data': data
        }
        return jsonify(response), 200
    elif request.method == 'GET':
        if stored_data is not None:
            return jsonify(stored_data), 200
        else:
            return jsonify({"message": "No data stored"}), 404

if __name__ == '__main__':
    app.run(debug=True)

