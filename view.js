import React from 'react'
import { View, TextInput, StyleSheet, Text, ListView, ActivityIndicator} from 'react-native'
import firebase from 'firebase';
import ComView from './com.js';


class Todo extends React.Component {

    constructor(props) {
        super(props)
        this.state = {
          com : [],
          text : ''
        }
    }

  componentWillMount() {
      var config = {
        apiKey: "AIzaSyDPHztV_TFYvA6F51mboJSoRq_vY1ZNouQ",
        authDomain: "appsoin.firebaseapp.com",
        databaseURL: "https://appsoin.firebaseio.com",
        projectId: "appsoin",
        storageBucket: "appsoin.appspot.com",
        messagingSenderId: "1071641365760"
      };

      if (!firebase.apps.length) {
        firebase.initializeApp(config);
      }

      firebase.database().ref('todo').on('value', (data) => {
        if (data.toJSON()) { 
          console.log(Object.values(data.toJSON()));
          this.setState({com : Object.values(data.toJSON())});
        }
      })
  }

  _add_text(text){
    if (text){
      firebase.database().ref('todo').push({
        coms : text
      }).then(() => {
        console.log('inserted');
      })
    }
  }

  _displayList() {
    const ds = new ListView.DataSource({rowHasChanged: (r1, r2) => r1 !== r2});
    if (!this.state.isLoading) {
      return(
      <View>
        <View style = {{height : 500}}>
        <ListView
          dataSource={ds.cloneWithRows(this.state.com)}
          enableEmptySections = {true}
          renderRow={(rowData) => <ComView com={rowData}/>}/>
        </View>
        <View>
          <TextInput
            onChangeText={(text) => this.setState({text : text})}
            onSubmitEditing = {() => this._add_text(this.state.text)}
            placeholder = 'Saivir votre comentaire'/>
        </View>
      </View>
      )
    }
  }

  render() {
      return (
        <View style>
          {this._displayList()}
        </View>
      )
    }
}

const styles = StyleSheet.create({

})

export default Todo
