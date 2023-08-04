from flask import Flask, request, jsonify
from flask_cors import CORS
from flask_sqlalchemy import SQLAlchemy
''''
FLASK CODE HANDLES, POST GET PUT REQUEST
IF PASSWORDS DONT MATCH , DOES NOT INSERT TO MYSQL!
'''


app = Flask(__name__)
CORS(app)

stored_data = None


# Database configuration using the parameters you provided
app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql://root:Fikr%40t2023@127.0.0.1/qt7'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False  # To suppress a warning


db = SQLAlchemy(app)



#define model for your data

class UserData(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True,nullable=False)
    mail = db.Column(db.String(120), unique=True, nullable=False)
    password = db.Column(db.String(120), nullable=False)
    repeatPassword = db.Column(db.String(120), nullable=False)  

    def __repr__(self):
	    return '<User %r>' % self.username

    
@app.before_request
def create_tables():
   
    db.create_all()
    
@app.route('/test', methods=['GET', 'POST', 'OPTIONS'])
def test():
    global stored_data
    if request.method == 'POST':
        data = request.get_json()
    
        stored_data = data
        
        print("Received data:", data)
        print("POST")
    
    
        if data["password"] != data["repeatPassword"]:
            return jsonify({"error:": "Passwords do not match"}), 400
         
        # Insert the received data into the database
        try:
            new_user = UserData(username=data["username"], mail=data["mail"], password=data["password"], repeatPassword=data["repeatPassword"])
            db.session.add(new_user)
            db.session.commit()

            response = {
            'message': 'Data received successfully',
            'data': data
            }
            return jsonify(response), 200
		
        except Exception as e:
                return jsonify({"error": "Failed to add user to database.", "details": str(e)}), 500
        
        
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

