from flask import Flask, jsonify, render_template, request
from comns import Communications
import json

app = Flask(__name__)
comn = Communications()

@app.route('/', methods=['GET', 'POST'])
def render_pie():
    if request.method == 'POST':
        comn.write("MOVE")
        print "POST"
    else:
        pass
    return render_template("index.html")



if __name__ == "__main__":
    app.run(debug=True)