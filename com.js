import React from 'react'
import { View , Button , TextInput,StyleSheet,Text,Image,ScrollView } from 'react-native'


class ComView extends React.Component {
  render() {
    const com = this.props.com;
    console.log(com);
      return (
        <Text>{com.coms}</Text>
      )
  }
}

export default ComView
