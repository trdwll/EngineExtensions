pipeline {
  options {
        disableConcurrentBuilds()
    }
  agent {
    node {
      label 'Windows'
    }
  }
  stages {
    stage('Build') {
      steps {
        bat "py -u C:\\jenkins.py EngineExtensions Build \"%WORKSPACE%\""
      }
    }

    stage('Publish') {
      when {
        branch "main"
      }
      steps {
        bat "py -u C:\\jenkins.py EngineExtensions Publish \"%WORKSPACE%\""
      }
    }
  }
}